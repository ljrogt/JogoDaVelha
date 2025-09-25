#include <stdio.h>
#include "modulosdeclaracao.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int area[3][3],linha,coluna;
string matriztexto="";


void igualar()
{
	int i,j;
	matriztexto="";
	for (i=0;i<=2;i++)
        {
                for (j=0;j<=2;j++)
                {
                        matriztexto=matriztexto+std::to_string(area[i][j]);
                }
        }
}
std::string parabase3(int n);

std::string parabase3(int n) {
    if (n==0) return "0";
    std::string res="";
    while (n>0) 
    {
        res= char('0'+n%3)+res;
        n/=3;
    }
    return res;
}

void bubblesort(int v[9],int n);
void bubblesort(int v[9], int n) 
{
	int i, j, temp;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j <n-i-1; j++) 
		{
			if (v[j] >v[j+1]) 
			{
				temp = v[j];
				v[j] =v[j+1];
				v[j+1] =temp;
			}
		}
	}

}


void jogadamaquina()
{
	int matriznumero=0,i=0,j=0,g=0,l,lc,p[9],b[9],k,po;
	std::string c;
	matriztexto="";
	for (i=0;i<9;i++)
	{
		p[i]=0;
	}
	igualar();
	l=matriztexto.size();
	cout << "Pensando." << flush;
       	for (i=0;i<3;i++)
	{
		this_thread::sleep_for(chrono::seconds(1));
		cout << "."<<flush;
	}	


	for (int i = 0; i < 9; i++)
        {
                if (matriztexto[i] == '0')
                {
                        matriztexto[i] = '2';
                        if (verificacao(matriztexto, 8) > 0)
                        {
                                matriztexto[i] = '2';
                                goto fim;
                        }
                        matriztexto[i] = '0';
                }
        }



	for (int i = 0; i < 9; i++) 
	{
		if (matriztexto[i] == '0') 
		{
    			matriztexto[i] = '1';
	    		if (verificacao(matriztexto, 1) > 0) 
			{                              
				matriztexto[i] = '2';
				goto fim;
			}
		       	matriztexto[i] = '0';
	 	}
    	}


	for (j=0;j<19683;j++)
	{
		i=1;
		g=0;
		matriznumero++;
		c=parabase3(matriznumero);
		lc=c.size();
		if(l<=lc)
		{
			while(i<=l)
			{
				if((matriztexto[l-i]-'0')!=0)
				{
					if((matriztexto[l-i]-'0')!=(c[lc-i]-'0'))
					{
						g=1;
					}
				}
				i++;
			}
		}
		else
		{
			while(i<=lc)
                        {
                                if((matriztexto[l-i]-'0')!=0)
                                {
                                        if((matriztexto[l-i]-'0')!=(c[lc-i]-'0'))
                                        {
                                                g=1;
                                        }
                                }
                                i++;
                        }

		}
		if (g==0)
		{
			k=verificacao(c,8);
			if(k==1)
			{
				for (i=1;i<=lc;i++)
				{
					if(c[lc-i]=='2')
					{
						p[9-i]++;
					}
				}
			}
		}
	}

	for (i=0;i<9;i++)
	{
		b[i]=p[i];
	}

	bubblesort(b,9);

	for(j=0;j<9;j++) 
	{ 
		for (i=0;i<9;i++)
	       	{ 
			if(b[8-j]==p[i])
			{ 
				po=i; 
				if(matriztexto[po]=='0') 
				{ 
					matriztexto[po]='2'; 
					goto fora; 
				}
			}       	
		}
       	}

	fora:
	fim:
	g=0;
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(area[i][j]==0&&matriztexto[g]-'0'==2)
			{
				cout<<"Jogando na posiçã("<<i<<","<<j<<")"<<flush;
				this_thread::sleep_for(chrono::seconds(1));
			}
			area[i][j]=matriztexto[g]-'0';
			g++;
		}
	}
}

int verificacao(string matriz,int n)
{
	int v=0,j=1;
	int vetormatriz[9];
       for (int i = 0; i < 9; i++) 
       {
       	       vetormatriz[i] = matriz[i] - '0';
       }
       for (int r = 0; r < 3; r++) 
       {
	       if (vetormatriz[3*r] * vetormatriz[3*r+1] * vetormatriz[3*r+2] == n) v++;
       }
       for(int c = 0; c < 3; c++)
       {
	       if (vetormatriz[c] * vetormatriz[c+3] * vetormatriz[c+6] == n) v++;
       }
       if (vetormatriz[0] * vetormatriz[4] * vetormatriz[8] == n) v++;
       if (vetormatriz[2] * vetormatriz[4] * vetormatriz[6] == n) v++;

       return v;
}

void areadejogo()
{
	for (linha=0;linha<=2;linha++)
        {
                for (coluna=0;coluna<=2;coluna++)
                {
                       area[linha][coluna]=0;
                }
        }

}

int vd()
{
	int i,j=1,v=1,d=2,e=3;

	for (i=0;i<9;i++)
	{
		j=j*(matriztexto[i]-'0');
	}

	if(verificacao(matriztexto,1)>0)
	{
		return v;
	}

	if(verificacao(matriztexto,8)>0)
	{
		return d;
	}

	if(j!=0)
	{
		return e;
	}

	return 0;

}

void mostrar()
{
	system("clear");
	printf("  0 1 2\n");
	printf("  -----\n");
        for (linha=0;linha<=2;linha++)
        {
		printf("%d|",linha);
                for (coluna=0;coluna<=2;coluna++)
                {
                       	printf ("%d ",area[linha][coluna]);
                }
                printf("\n");
        }
}

int escolherjogada(int p)
{
	int x,y;
	printf("Você joga com o '%d', escolha a posição que quer jogar(escolha '3' se quiser parar)!\n",p);
	while (true)
	{
		printf("Linha:");
		scanf("%d",&x);
		if(x==3)
		{
			return x;
		}
		printf("Coluna:");
		scanf("%d",&y);
		if (area[x][y]==0)
		{
			area[x][y]=p;
			break;
		}
	}
	mostrar();
	return 0;
}


int menuprincipal()
{
	int escolha;
	system("clear");
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\nBem vindo ao JOGO DA VELHA");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n");
	printf("Escolha uma opcao");
	printf("\n0 - Jogar jogador x máquina");
	printf("\n1 - Jogar jogador x jogador");
	printf("\n2 - Sair");
	printf("\n-------------------------\n");
	while(true)
	{
		scanf("%d",&escolha);
		if(escolha==1||escolha==0||escolha==2)
		{
			break;
		}
	};
	return escolha;

}

int menupvp()
{
	int escolha;
        system("clear");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\nJOGADOR CONTRA JOGADOR");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n");
        printf("Escolha uma opcao");
        printf("\n0 - Jogar");
        printf("\n1 - Sair");
        printf("\n2 - Placar");
        printf("\n-------------------------\n");
        while(true)
        {
                scanf("%d",&escolha);
                if(escolha==1||escolha==0||escolha==2)
                {
                        break;
                }
        };
        return escolha;
}

int menupm()
{
	int escolha;
        system("clear");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\nJOGANDO CONTRA A MÁQUINA");
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n");
        printf("Escolha uma opcao");
        printf("\n0 - Jogar");
	printf("\n1 - Sair");
        printf("\n2 - Placar");
        printf("\n-------------------------\n");
        while(true)
        {
                scanf("%d",&escolha);
                if(escolha==1||escolha==0||escolha==2)
                {
                        break;
                }
        };
        return escolha;
}
