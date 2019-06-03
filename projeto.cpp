#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include "bibprojeto.h" // inclus�o da biblioteca utiliada no projeto;

// PROJETO DE ALGORITMOS II
// Shopping Control.

int main ()
 {
	int resp=0, slc=0; 
	char op;
	
	setlocale(LC_ALL,"PORTUGUESE");
	
	funBV(); // chamando a fun��o para dizer bem vindo;
	
	resp = menu ();	// chamando menu principal;
	system ("cls");
	do{ // entrando no la�o de chamada de submenus; 
		switch(resp){
			case 1: // a op��o 1 no menu principal � para cadastrar novo locat�rio;
				system("cls");
				printf("\n\tDeseja cadastrar novo locatario?(s/n)\n");
				scanf("%s", &op);
				if(op=='s'||op=='S'){
					resp=cad(op); // chamando a fun��o de cadastro;
					system("cls");
				}
				else{
					system("cls");
					resp=menu();
				}
				break;
			case 2: // a op��o 2 no menu principal chama um submenu para op��es de acesso ao arquivo;
				system("cls");
				resp=menulist(); // submenu para op��es do arquivo;
				break;
			case 3: // a op��o 3 no menu principal chama uma fun��o j� levando um par�metro para
					// direcionar o que ser� executado na fun��o;
				system("cls");
				printf("\t#########################################");
				printf("\n\t1 - Desativar cadastro\n");
				printf("\n\t2 - Editar cadastro\n");
				printf("\t#########################################\n");
				fflush(stdin);
				scanf("%d", &slc);
				system("cls");
				resp=gerenciar(slc); // chamando fun��o para gerenciamento e levando a op��o como par�metro;
				break;
			case 4: // a op��o 4 no menu principal faz com que todo o programa encerre;
				system("cls");
				printf("\n\tOpera��o Encerrada.\n");
				system("pause");				
				break;
			case 0: // caso retorne um 0 do menu principal, o menu() � chamado novamente
					// procedimento necessario pois o usu�rio poder� continuar usando o programa
					// ap�s utilizar outras funcionalidades;
				system("cls");
				resp=menu();
				break;
			default: // em outros casos o menu() tamb�m ser� chamado novamente;
				printf("\n\tOp��o inv�lida.");
				Sleep(1000);
				resp=menu();
				break;
		}
	}while(resp!=4); // �nica condi��o para encerrar definitivamente o la�o;
}
