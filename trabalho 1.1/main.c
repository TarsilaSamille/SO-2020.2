
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t begin, end;
    char s_begin[50], s_end[50];
    pid_t filho1, filho2, neto1, neto2;

    begin = time(NULL);
    strftime(s_begin,sizeof(s_begin),"%d/%m/%Y %H:%M:%S",localtime(&begin));
    printf("O pai nasceu em %s com PID = %d\n", s_begin, getpid());

    sleep(14);
    filho1 = fork();
    
    if (filho1 < 0) {
        printf("Erro ao criar processo!!!\n");
        return 1;
    }
    if (filho1 == 0) {
        begin = time(NULL);
        strftime(s_begin,sizeof(s_begin),"%d/%m/%Y %H:%M:%S",localtime(&begin));
        printf("O filho 1 nasceu em %s com PID = %d\n", s_begin, getpid());
        sleep(12);
        neto1 = fork();
        if (neto1 < 0) {
            printf("Erro ao criar processo!!!\n");
        }
        if (neto1 == 0) {
            begin = time(NULL);
            strftime(s_begin,sizeof(s_begin),"%d/%m/%Y %H:%M:%S",localtime(&begin));
            printf("O neto 1 nasceu em %s com PID = %d\n", s_begin, getpid());
            sleep(12);
            end = time(NULL);
            strftime(s_end,sizeof(s_end),"%d/%m/%Y %H:%M:%S",localtime(&end));
            printf("O neto 1(%d) morreu com %d anos, tempo de vida: %s - %s \n",  getpid() , (int) difftime(end, begin), s_begin, s_end);
            exit(0);
        }
        sleep(18);
        end = time(NULL);
        strftime(s_end,sizeof(s_end),"%d/%m/%Y %H:%M:%S",localtime(&end));
        printf("O filho 1(%d) morreu com %d anos, tempo de vida: %s - %s \n",  getpid() , (int) difftime(end, begin), s_begin, s_end);
        exit(0);
    }

    sleep(2);
    filho2 = fork();
    if (filho2 < 0) {
        printf("Erro ao criar processo!!!\n");
        return 1;
    }
    if (filho2 == 0) {
        begin = time(NULL);
        strftime(s_begin,sizeof(s_begin),"%d/%m/%Y %H:%M:%S",localtime(&begin));
        printf("O filho 2 nasceu em %s com PID = %d\n", s_begin, getpid());
        sleep(14);
        neto2 = fork();
        if (neto2 < 0) {
            printf("Erro ao criar processo!!!\n");
        }
        if (neto2 == 0) {
            begin = time(NULL);
            strftime(s_begin,sizeof(s_begin),"%d/%m/%Y %H:%M:%S",localtime(&begin));
            printf("O neto 2 nasceu em %s com PID = %d\n", s_begin, getpid());
            sleep(18);
            end = time(NULL);
            strftime(s_end,sizeof(s_end),"%d/%m/%Y %H:%M:%S",localtime(&end));
            printf("O neto 2(%d) morreu com %d anos, tempo de vida: %s - %s \n", getpid() , (int) difftime(end, begin), s_begin, s_end);
            exit(0);
        }
        sleep(16);
        end = time(NULL);
        strftime(s_end,sizeof(s_end),"%d/%m/%Y %H:%M:%S",localtime(&end));
        printf("O filho 2(%d) morreu com %d anos, tempo de vida: %s - %s \n", getpid() , (int) difftime(end, begin), s_begin, s_end);
        exit(0);
    }
    sleep(44);
    end = time(NULL);
    strftime(s_end,sizeof(s_end),"%d/%m/%Y %H:%M:%S",localtime(&end));
    printf("O pai(%d) morreu com %d anos, tempo de vida: %s - %s \n", getpid() , (int) difftime(end, begin), s_begin, s_end);
    return 0;
}
