#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::setVelocidade(int value){
    velocidade = value;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1: //Trem 1
            if (y == 30 && x <330){
                x+=10;
                if(x == 320){
                    areaCriticaT14.lock();
                    areaCriticaT12.lock();
                }
            }
            else if (x == 330 && y < 150){
                y+=10;
                //if(y == 140)
                //    areaCriticaT14.lock();
            }
            else if (x > 60 && y == 150){
                x-=10;
                if(x == 320)
                    areaCriticaT12.unlock();
                if(x == 180)
                    areaCriticaT14.unlock();
            }
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 30 && x <600){
                x+=10;
                if(x == 340)
                    areaCriticaT12.unlock();
                if(x == 590)
                    areaCriticaT23.lock();
            }
            else if (x == 600 && y < 150){
                y+=10;
                if(y == 140)
                    areaCriticaT25.lock();
            }
            else if (x > 330 && y == 150){
                x-=10;
                if(x == 340)
                    areaCriticaT12.lock();
                if(x == 590)
                    areaCriticaT23.unlock();
                if(x == 440)
                    areaCriticaT25.unlock();
                if(x == 480)
                    areaCriticaT24.lock();
            }
            else{
                y-=10;
                if(y == 130)
                    areaCriticaT24.unlock();
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 30 && x <870){
                x+=10;
                if(x == 610)
                    areaCriticaT23.unlock();
            }
            else if (x == 870 && y < 150)
                y+=10;
            else if (x > 600 && y == 150){
                x-=10;
                //if(x == 610)
                //    areaCriticaT23.lock();
                if(x == 750){
                    areaCriticaT23.lock();
                    areaCriticaT35.lock();
                }
            }
            else{
                y-=10;
                if(y == 130)
                    areaCriticaT35.unlock();
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (y == 150 && x <465){
                x+=10;
                if(x == 355)
                    areaCriticaT14.unlock();
                //if(x == 455)
                //    areaCriticaT45.lock();
                if(x == 315){
                    areaCriticaT45.lock();
                    areaCriticaT24.lock();
                }
            }
            else if (x == 465 && y < 270){
                y+=10;
                if(y == 170)
                    areaCriticaT24.unlock();
            }
            else if (x > 195 && y == 270){
                x-=10;
                if(x == 455)
                    areaCriticaT45.unlock();
            }
            else{
                y-=10;
                if(y == 160)
                    areaCriticaT14.lock();
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            if (y == 150 && x <735){
                x+=10;
                if(x == 475)
                    areaCriticaT45.unlock();
                if(x == 625)
                    areaCriticaT25.unlock();
                if(x == 585)
                    areaCriticaT35.lock();
            }
            else if (x == 735 && y < 270){
                y+=10;
                if(y == 170)
                    areaCriticaT35.unlock();
            }
            else if (x > 465 && y == 270){
                x-=10;
                if(x== 475)
                    areaCriticaT45.lock();
            }
            else{
                y-=10;
                if(y == 160)
                    areaCriticaT25.lock();
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        while(velocidade == 200)
            msleep(1);
        msleep(velocidade);
    }
}




