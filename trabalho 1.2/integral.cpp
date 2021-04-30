#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <math.h>

using namespace std;

#define PI 3.14159265

//double a = 0, b = 10; // f1
double a=0, b=2*PI;  //f2

double h, sum = 0, integral;
int n, t, trapezio_por_thread;
double * x, * y;

struct thread_data {
    int thread_id;
};

double f1(double x) {
    return 5;
}
double f2(double x) {
    return sin(2.0 * x) + cos(5.0 * x);
}

void * fun(void * threadarg) {
    struct thread_data * my_data;
    my_data = (struct thread_data * ) threadarg;
    int inicio = my_data -> thread_id * trapezio_por_thread;
    int fim = (inicio + trapezio_por_thread) >= t ? t : (inicio + trapezio_por_thread);
    for (int i = inicio; i < fim; i++) {
        x[i] = a + i * h;
        y[i] = f2(x[i]);
        if (i!=0 && i!= t) sum += h * y[i];
    }
    pthread_exit(NULL);
}

int main(int argc, char * argv[]) {

    cout << "Digite o numero de threads:";
    cin >> n;
    cout << "Digite o numero de trapezios:";
    cin >> t;
    
    int rc;
    pthread_t threads[n];
    struct thread_data td[n];
    h = (b - a) / t;
    trapezio_por_thread = ceil((double)t / n);
    x = new double[t];
    y = new double[t];
    
    for (int i = 0; i < n; i++) {
        td[i].thread_id = i;
        rc = pthread_create( & threads[i], NULL, fun, (void * ) & td[i]);
        if (rc) {
            cout << "Error," << rc << endl;
            exit(-1);
        }
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    integral = h / 2.0 * (y[0] + y[t - 1]) + sum;
    cout.precision(2);
    cout<<scientific;
    cout << "\nA integral é " << integral << endl;

    pthread_exit(NULL);

}