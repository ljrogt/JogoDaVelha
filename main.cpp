#include <stdio.h>
#include <stdlib.h>
#include "modulosdeclaracao.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

int main()
{
	int x,y,estadojogo,funcionamento,res,area[3][3],i,j,placar[3];

	placar[1]=0;
	placar[0]=0;
	placar[2]=0;

	

	while (true)
	{
		funcionamento=menu();
		while(funcionamento==2)
                {
                        system("clear");
			std::cout<<"\n=-=-=-=-=-=-"<<std::flush;
			std::cout<<"\nPLACAR GERAL"<<std::flush;
			std::cout<<"\n=-=-=-=-=-=-"<<std::flush;
			std::cout<<"\nMaquina("<<placar[1]<<")xJogador("<<placar[0]<<")|Empate("<<placar[2]<<")"<<std::flush;
			std::this_thread::sleep_for(std::chrono::seconds(3));
                        funcionamento=menu();
			if(funcionamento==1)
			{
				break;
			}
                }
		if(funcionamento==1)
                {
                        break;
                }

		areadejogo();
		mostrar();
		estadojogo=0;
		while (estadojogo==0)
		{
			printf("Você joga com o '1', escolha a posição que quer jogar(escolha '3' se quiser parar)!\n");
			printf("Linha:");
			scanf("%d",&x);
			if(x==3)
			{
				break;
			}
			printf("Coluna:");
			scanf("%d",&y);
			escolherjogada(x,y);
			jogadamaquina();
			mostrar();
			estadojogo=vd();
			if (estadojogo==1)
			{
				std::cout<<"VITÓRIA"<<std::flush;
				placar[0]++;
			}
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
	
}
