#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include "bibprojeto.h" // inclusão da biblioteca utiliada no projeto;

// PROJETO DE ALGORITMOS II
// Shopping Control.

int main ()
 {
	int resp=0, slc=0; 
	char op;
	
	setlocale(LC_ALL,"PORTUGUESE");
	
	funBV(); // chamando a função para dizer bem vindo;
	
	resp = menu ();	// chamando menu principal;
	system ("cls");
	do{ // entrando no laço de chamada de submenus; 
		switch(resp){
			case 1: // a opção 1 no menu principal é para cadastrar novo locatário;
				system("cls");
				printf("\n\tDeseja cadastrar novo locatario?(s/n)\n");
				scanf("%s", &op);
				if(op=='s'||op=='S'){
					resp=cad(op); // chamando a função de cadastro;
					system("cls");
				}
				else{
					system("cls");
					resp=menu();
				}
				break;
			case 2: // a opção 2 no menu principal chama um submenu para opções de acesso ao arquivo;
				system("cls");
				resp=menulist(); // submenu para opções do arquivo;
				break;
			case 3: // a opção 3 no menu principal chama uma função já levando um parâmetro para
					// direcionar o que será executado na função;
				system("cls");
				printf("\t#########################################");
				printf("\n\t1 - Desativar cadastro\n");
				printf("\n\t2 - Editar cadastro\n");
				printf("\t#########################################\n");
				fflush(stdin);
				scanf("%d", &slc);
				system("cls");
				resp=gerenciar(slc); // chamando função para gerenciamento e levando a opção como parâmetro;
				break;
			case 4: // a opção 4 no menu principal faz com que todo o programa encerre;
				system("cls");
				printf("\n\tOperação Encerrada.\n");
				system("pause");				
				break;
			case 0: // caso retorne um 0 do menu principal, o menu() é chamado novamente
					// procedimento necessario pois o usuário poderá continuar usando o programa
					// após utilizar outras funcionalidades;
				system("cls");
				resp=menu();
				break;
			default: // em outros casos o menu() também será chamado novamente;
				printf("\n\tOpção inválida.");
				Sleep(1000);
				resp=menu();
				break;
		}
	}while(resp!=4); // única condição para encerrar definitivamente o laço;
}
