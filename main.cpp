#include <stdio.h>
#include <stdlib.h>
#include "modulosdeclaracao.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

int placar[3];
void zerarplacar();
void zerarplacar()
{
	placar[1]=0;
        placar[2]=0;
        placar[0]=0;
}

int main()
{
	int x,y,estadojogo,funcionamento,res,area[3][3],i,j;


	while(true){
	int jogo=menuprincipal();

	while (jogo==0)
	{
		funcionamento=menupm();
		while(funcionamento==2)
                {
                        system("clear");
			std::cout<<"\n=-=-=-=-=-=-"<<std::flush;
			std::cout<<"\nPLACAR GERAL"<<std::flush;
			std::cout<<"\n=-=-=-=-=-=-"<<std::flush;
			std::cout<<"\nMaquina("<<placar[1]<<")xJogador("<<placar[0]<<")|Empate("<<placar[2]<<")"<<std::flush;
			std::this_thread::sleep_for(std::chrono::seconds(3));
                        funcionamento=menupm();
			if(funcionamento==1)
			{
				break;
			}
                }
		if(funcionamento==1)
                {
			zerarplacar();
                        break;
                }

		areadejogo();
		mostrar();
		estadojogo=0;
		while (estadojogo==0)
		{
			x=escolherjogada(1);
			if(x==3)
			{
				break;
			}
			estadojogo=vd();
                        if (estadojogo==1)
                        {
                                std::cout<<"VITÓRIA"<<std::flush;
                                placar[0]++;
                        }
			jogadamaquina();
			mostrar();
			estadojogo=vd();
			if(estadojogo==2)
			{
				std::cout<<"DERROTA"<<std::flush;
				placar[1]++;
			}
			if(estadojogo==3)
			{
				std::cout<<"EMPATE"<<std::flush;
				placar[2]++;
			}
			
			
		}
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
	while (jogo==1)
        {
                funcionamento=menupvp();
                while(funcionamento==2)
                {
                        system("clear");
                        std::cout<<"\n=-=-=-=-=-=-"<<std::flush;
                        std::cout<<"\nPLACAR GERAL"<<std::flush;
                        std::cout<<"\n=-=-=-=-=-=-"<<std::flush;
                        std::cout<<"\nJogador[2]("<<placar[1]<<")xJogador[1]("<<placar[0]<<")|Empate("<<placar[2]<<")"<<std::flush;
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        funcionamento=menupvp();
                        if(funcionamento==1)
                        {
                                break;
                        }
                }
                if(funcionamento==1)
                {
			zerarplacar();
                        break;
                }

                areadejogo();
                mostrar();
                while (true)
                {
			x=0;
			estadojogo=0;
                        x=escolherjogada(1);
			if(x==3)
			{
				break;
			}
			igualar();
                        estadojogo=vd();
                        if (estadojogo==1)
                        {
                                std::cout<<"VITÓRIA [1]"<<std::flush;
                                placar[0]++;
                                goto fo;
                        }
			x=escolherjogada(2);
			if(x==3)
			{
				break;
			}
			igualar();
			estadojogo=vd();
                        if(estadojogo==2)
                        {
                                std::cout<<"VITÓRIA [2]"<<std::flush;
                                placar[1]++;
				goto fo;
                        }
                        if(estadojogo==3)
                        {
                                std::cout<<"EMPATE"<<std::flush;
                                placar[2]++;
				goto fo;
                        }
		}
		fo:
                std::this_thread::sleep_for(std::chrono::seconds(3));
        }

	if (jogo==2)
	{
		break;
	}
	}
}
