#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

// BIBLIOTECA DO PROGRAMA Shopping Control.

struct cadastro{
	char nome_prop[50], nome_empre[50], local[50], info[50], status[10];
	int cnpj=0, id=0;
	float valor=0;
};

void funBV ()
{
	printf ("\t   _______________________________________________________________________________________\n");
	printf ("\t  |                                                                                       |\n");
	printf ("\t  |    ######    #######   ###     ###       #       #   #  ##     #   #####    #####     |\n");
	printf ("\t  |    #     #   #         #  #   #  #        #     #    #  # #    #   #    #  #     #    |\n");
	printf ("\t  |    # # #     ######    #   # #   #         #   #     #  #  #   #   #    #  #     #    |\n");
	printf ("\t  |    #     #   #         #    #    #          # #      #  #   #  #   #    #  #     #    |\n");
	printf ("\t  |    ######    #######   #         #           #       #  #    ##    #####    #####     |\n");
	printf ("\t  |_______________________________________________________________________________________|\n\n");
	printf ("\t                                                                      * SHOPPING CONTROL * \n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(2100);
	system ("cls");
}
int menu () // MENU PRINCIPAL;
{	
	int op=0;
	
	system("cls");
	printf ("\t   ________________________________________________________________________________________________________\n");
	printf ("\t  |                                                                                                        |\n");
	printf ("\t  |    ###   ###  #####  ##   #  #   #    ######   #####   #  ##   #   # # #  #  ######    ####   #        |\n");
	printf ("\t  |    #  # #  #  #___   # #  #  #   #    #     #  #    #  #  # #  #  #       #  #     #  #    #  #        |\n");
	printf ("\t  |    #   #   #  #      #  # #  #   #    #### #   #  #    #  #  # #  #       #  #### #   # ## #  #        |\n");
	printf ("\t  |    #       #  #####  #   ##  #####    #        #    #  #  #   ##   # # #  #  #        #    #  # # #    |\n");
	printf ("\t  |________________________________________________________________________________________________________|\n\n");
	
	printf ("\t   ________________________________________________________________________________________________________\n");
	printf ("\t  |                                                                                                        |\n");
	printf ("\t  |            1 ->  Cadastrar novo Cliente.                                                               |\n");
	printf ("\t  |            2 ->  Arquivo                                                                               |\n");
	printf ("\t  |            3 ->  Gerenciamento                                                                         |\n");
	printf ("\t  |            4 ->  Sair                                                                                  |\n");
	printf ("\t  |________________________________________________________________________________________________________|\n\n");
	
	printf ("\n\t POR FAVOR DIGITE A OPÇÃO DESEJADA:\n");
	scanf ("%d", &op); 
	return op; // Retornando para o programa principal;
	system("cls");
	
}

void restidi(int *idi) // Função para comparar a variável declarada 'i' para auxiliar no registro de ID's na função cad()
{						// com o maior id registrado no arquivo;
	struct cadastro cd;
	FILE *arq; // declarando ponteiro para a variável'arq' do tipo FILE, referente ao arquivo;
	arq=fopen("ark.txt", "rb"); // abrindo arquivo para leitura;
	while(fread(&cd, sizeof(struct cadastro), 1, arq)) // enquanto houver informação para leitura no arquivo
	{
	
	if (cd.id<=*idi) // compara com o 'i' e se for menor ou igual o registro:
	{
		*idi = cd.id+1;  //faz o 'i' receber o valor que está no registro + 1 para cadastrar o próximo sequencialmente;
	}
	
	};
	fclose(arq); // fechar o arquivo;
	fflush(arq); // comando para limpar o "caminho de abertura e fechmanto de arquivo" para evitar erros;	
}

void sortCNPJ(struct cadastro *V, int N) // função para ordenar os cadastros em ordem numérica com base no CNPJ;
{
    int i, j;
    struct cadastro aux;
    for(i = 1; i < N; i++)
    {
        aux = V[i];
        j = i - 1;
        for(j=i;(j>0)&&(aux.cnpj<V[j-1].cnpj);j--)
        V[j] = V[j-1];
        V[j]=aux;
	}          
 }
 
 void sortNome(struct cadastro *V, int N) // função para ordenar os cadastros em ordem alfabética com base no nome da empresa cadastrada;
{
    int i, j;
    struct cadastro aux;
    for(i = 1; i < N; i++)
    {
        aux = V[i];
        j = i - 1;
        for(j=i;(j>0)&&(strcmp(aux.nome_empre,V[j-1].nome_empre)<0);j--)
        {
		V[j] = V[j-1];
        V[j-1]= aux;
        }	  
	}
}
   
int consul(int op){	// função para chamar funções de ordenção e printar a lista em ordem;
	int i=0, j=0, n=0, ch=0;
	FILE *arq;
	
	// abrindo arquivo e lendo 
	arq=fopen("ark.txt", "r");
	while((ch=fgetc(arq))!=EOF){ // enaquanto for diferente do fim do arquivo o 'ch' recebe tudo que tem no arquivo um dado por vez
		if(ch='\n'){ // se o que o ch receber for uma quebra de linha o j incrementa 1;
			j++;
		}
	}		
	fclose(arq);
	fflush(arq);
	
	struct cadastro cd[j/224]; // o j é o total de linhas dentro do arquivo e 224 é o número de linhas que uma posição do vetor da struct ocupa.
	
	n=j/224; // fazendo uma variável receber o tamanho para enviá-la nas funções; 
	arq=fopen("ark.txt", "rb");
	
	fread(cd, sizeof(struct cadastro), j/224, arq); // comando de leitura e preenchimento do vetor de struct com o tamanho do vetor j/224; 
	
	fclose(arq);
	printf("%d", j);
	if(op==2){ // se a opção escolhida anteriormente no menu do arquivo foi ordenar por CNPJ
		sortCNPJ(cd, n); // chamar a ordenação por CNPJ levando o vetor de struct cd e o tamanho n;
	}
	else if(op==1){ // se a opção escolhida anteriormente no menu do arquivo foi ordenar em ordem alfabética com base no nome
		sortNome(cd, n); // chamar a ordenação por nome levando o vetor de struct cd e o tamanho n;
	}
	for(i=0;i<j/224;i++){ // laço para printar registros já ordenados;
		if(strcmp(cd[i].status, "Ativo")==0){
			printf("\n\t###################################\n");
			printf("\n\tID: %d", cd[i].id);
			printf("\n\tEmpresa: %s", cd[i].nome_empre);
			printf("\n\tCNPJ: %d", cd[i].cnpj);
			printf("\n\tProprietário: %s", cd[i].nome_prop);
			printf("\n\tLocal: %s", cd[i].local);
			printf("\n\tAluguel: %0.2f", cd[i].valor);
			printf("\n\tInformações: %s", cd[i].info);
			printf("\n\tStatus: %s", cd[i].status);
			printf("\n\n");
		}
	}
	system("pause");
	return 0; // retorna 0 para induzir a volta para o menu principal;
}
 
int searchcad(int op){ // função para pesquisar/consultar um locatário específico;
	int i=0, j=0, n=0, cnpj=0, ch=0;
	char nome[50];
	FILE *arq;
	
	arq=fopen("ark.txt", "r");
	while((ch=fgetc(arq))!=EOF){
		if(ch='\n'){
			j++;
		}
	}		
	fclose(arq);
	fflush(arq);
	
	struct cadastro cds[j/224];
	
	n=j/224;
	arq=fopen("ark.txt", "rb");
	
	fread(cds, sizeof(struct cadastro), j/224, arq);
	
	fclose(arq);
	if(op==1){
		printf("\n\tFavor informe o nome da empresa a ser consultada: ");
		fflush(stdin);
		gets(nome);
		for(i=0;i<j/224;i++){
			if(strcmp (nome,cds[i].nome_empre)==0){                  // comparando se a variável nome capturada anteriormente 
				printf("\n\t###################################\n");   // é igual ao nome da empresa registrada no arquivo;
				printf("\n\tID: %d", cds[i].id);
				printf("\n\tEmpresa: %s", cds[i].nome_empre);
				printf("\n\tCNPJ: %d", cds[i].cnpj);
				printf("\n\tProprietário: %s", cds[i].nome_prop);
				printf("\n\tLocal: %s", cds[i].local);
				printf("\n\tAluguel: %0.2f", cds[i].valor);
				printf("\n\tInformações: %s", cds[i].info);
				printf("\n\tStatus: %s", cds[i].status);
				printf("\n\n");
				system("pause");
			}
		}
	}
	else if(op==2){
		printf("\n\tFavor informe o CNPJ da empresa a ser consultada: ");
		fflush(stdin);
		scanf("%d", &cnpj);
		for(i=0;i<j/224;i++){
			if(cnpj==cds[i].cnpj){ 									// comparando se a variável cnpj capturada anteriormente 
				printf("\n\t###################################\n");  // é igual ao cnpj registrado no arquivo;
				printf("\n\tID: %d", cds[i].id);
				printf("\n\tEmpresa: %s", cds[i].nome_empre);
				printf("\n\tCNPJ: %d", cds[i].cnpj);
				printf("\n\tProprietário: %s", cds[i].nome_prop);
				printf("\n\tLocal: %s", cds[i].local);
				printf("\n\tAluguel: %0.2f", cds[i].valor);
				printf("\n\tInformações: %s", cds[i].info);
				printf("\n\tStatus: %s", cds[i].status);
				printf("\n\n");
				system("pause");
			}
		}
	}
	return 0; // retornando 0 para voltar automaticamente ao menu principal.
}

int desative() // função para desativar um cadastro.
{
	int i=0, j=0, n=0, cnpj=0, ch=0;
	char p;
	FILE *arq;
	
	arq=fopen("ark.txt", "r");
	while((ch=fgetc(arq))!=EOF){
		if(ch='\n'){
			j++;
		}
	}		
	fclose(arq);
	fflush(arq);
	
	struct cadastro cdd[j/224];
	
	arq=fopen("ark.txt", "rb");
	
	fread(cdd, sizeof(struct cadastro), j/224, arq);
	
	fclose(arq);
	
		printf("\n\tFavor informe o CNPJ da empresa a ser desativada do sistema: ");
		fflush(stdin);
		scanf("%d", &cnpj);
		system("cls");
		printf("\n\tPor favor confira os dados abaixo:");
		for(i=0;i<j/224;i++){
			if(cnpj==cdd[i].cnpj){ // comparando o cnpj digitdo com os cnpj do vetor da struct; 
				printf("\n\t###################################\n");
				printf("\n\tID: %d", cdd[i].id);
				printf("\n\tEmpresa: %s", cdd[i].nome_empre);
				printf("\n\tCNPJ: %d", cdd[i].cnpj);
				printf("\n\tProprietário: %s", cdd[i].nome_prop);
				printf("\n\tLocal: %s", cdd[i].local);
				printf("\n\tAluguel: %0.2f", cdd[i].valor);
				printf("\n\tInformações: %s", cdd[i].info);
				printf("\n\tStatus: %s", cdd[i].status);
				printf("\n\n");
				printf("\n\tDeseja confirmar desativação?(s/n)");
				fflush(stdin);
				scanf("%s", &p);
				if(p=='s'||p=='S'){
					strcpy(cdd[i].status, "desativado"); // sobreescrevendo o status antigo para desativado;
					n=remove("ark.txt"); // comando para excluir o arquivo antigo;
					arq=fopen("ark.txt", "a+"); // criando e abrindo um novo arquivo com o mesmo nome do antigo;
					if(arq==NULL){ // se o ponteiro for igual a NULL quer dizer que ocorreu um erro na abertura do arquivo;
						printf("\n\tErro na abertura do arquivo.\n");
						system("pause");
						exit(1);
					}
					fflush(stdin);
					fflush(arq);
					fwrite (&cdd, sizeof(struct cadastro), j/224, arq);
					if(fwrite != 0){ // se o comando fwrite for diferente de 0 quer dizer que pelo menos uma linha foi alterada dentro do arquivo;
				    	printf("\tDados salvos com sucesso!\n"); 
				    	system("pause");
				    	system("cls");
				   	}
				   	else{
				    	printf("Erro ao salvar.\n");
				    	system("pause");
				    	system("cls");
				    }
				    fclose(arq);
				    fflush(arq);
				    return 0;
				}
				else{
					return 0;
				}
			}
		}
}

int edit() // função para edição de dados de um cadastro ativo e para ativção de um cadastro inativo.
{
	int i=0, y=0, op=0, opp=0, j=0, n=0, cnpj=0, campo=0, ch=0;
	char nome[50], regs[50], p;
	float regf=0;
	FILE *arq;
	
	arq=fopen("ark.txt", "r");
	while((ch=fgetc(arq))!=EOF){
		if(ch='\n'){
			j++;
		}
	}		
	fclose(arq);
	fflush(arq);
	
	struct cadastro cdd[j/224];
	
	arq=fopen("ark.txt", "rb");
	
	fread(cdd, sizeof(struct cadastro), j/224, arq);
	
	fclose(arq);
	
		printf("\t#########################################");
		printf("\n\t1 - Editar dados do cadastro\n");
		printf("\n\t2 - Reativar Cadastro\n");
		printf("\t#########################################\n");
		fflush(stdin);
		scanf("%d", &opp);
		system("cls");
		if(opp==1){ // se a opção for editar cadastro;
			printf("\n\tFavor informe o CNPJ da empresa a ser editado no sistema: ");
			fflush(stdin);
			scanf("%d", &cnpj);
			printf("\n\tPor favor confira os dados abaixo:");
			for(i=0;i<j/224;i++){
				if(cnpj==cdd[i].cnpj){
					y=i;
					printf("\n\t###################################\n");
					printf("\n\tID: %d", cdd[i].id);
					printf("\n\tEmpresa: %s", cdd[i].nome_empre);
					printf("\n\tCNPJ: %d", cdd[i].cnpj);
					printf("\n\tProprietário: %s", cdd[i].nome_prop);
					printf("\n\tLocal: %s", cdd[i].local);
					printf("\n\tAluguel: %0.2f", cdd[i].valor);
					printf("\n\tInformações: %s", cdd[i].info);
					printf("\n\tStatus: %s", cdd[i].status);
					printf("\n\n");
				}
			}
					printf("\n\tDeseja fazer alguma alteração?(s/n)\n\n");
					fflush(stdin);
					scanf("%s", &p);
					if(p=='s'||p=='S'){
						do{
							printf("\n\tInforme o número do campo a ser modificado: ");
							printf("\n\t1 - Empresa");
							printf("\n\t2 - CNPJ");
							printf("\n\t3 - Proprietário");
							printf("\n\t4 - Local");
							printf("\n\t5 - Informações");
							printf("\n\t6 - Valor\n");
							fflush(stdin);
							scanf("%d", &campo);
							if(campo==1){
								printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
								fflush(stdin);
								gets(regs);
								strcpy(cdd[y].nome_empre, regs);
								system("cls");
								printf("\t########################################\n\n");
								printf("\tnome da empresa: %s\n", cdd[y].nome_empre);
								printf("\tCNPJ: %d\n", cdd[y].cnpj);
								printf("\tnome: %s\n", cdd[y].nome_prop);
								printf("\tlocal de alocação: %s\n", cdd[y].local);
								printf("\tvalor da alocação: %0.2f\n", cdd[y].valor);
								printf("\tinformações:\n \t%s\n\n", cdd[y].info);
								printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
								scanf("%d", &op);
								system("cls");
							}
							if(campo==2){
								printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
								fflush(stdin);
								scanf("%f", &regf);
								cdd[y].cnpj=regf;
								system("cls");
								printf("\t########################################\n\n");
								printf("\tnome da empresa: %s\n", cdd[y].nome_empre);
								printf("\tCNPJ: %d\n", cdd[y].cnpj);
								printf("\tnome: %s\n", cdd[y].nome_prop);
								printf("\tlocal de alocação: %s\n", cdd[y].local);
								printf("\tvalor da alocação: %0.2f\n", cdd[y].valor);
								printf("\tinformações:\n \t%s\n\n", cdd[y].info);
								printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
								scanf("%d", &op);
								system("cls");
							}
							if(campo==3){
								printf("\n\tPor favor entre com o novo dado a ser inserido no campo: ");
								fflush(stdin);
								gets(regs);
								strcpy(cdd[y].nome_prop, regs);
								system("cls");
								printf("\t########################################\n\n");
								printf("\tnome da empresa: %s\n", cdd[y].nome_empre);
								printf("\tCNPJ: %d\n", cdd[y].cnpj);
								printf("\tnome: %s\n", cdd[y].nome_prop);
								printf("\tlocal de alocação: %s\n", cdd[y].local);
								printf("\tvalor da alocação: %0.2f\n", cdd[y].valor);
								printf("\tinformações:\n \t%s\n\n", cdd[y].info);
								printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
								scanf("%d", &op);
								system("cls");
							}
							if(campo==4){
								printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
								fflush(stdin);
								gets(regs);
								strcpy(cdd[y].local, regs);
								system("cls");
								printf("\t########################################\n\n");
								printf("\tnome da empresa: %s\n", cdd[y].nome_empre);
								printf("\tCNPJ: %d\n", cdd[y].cnpj);
								printf("\tnome: %s\n", cdd[y].nome_prop);
								printf("\tlocal de alocação: %s\n", cdd[y].local);
								printf("\tvalor da alocação: %0.2f\n", cdd[y].valor);
								printf("\tinformações:\n \t%s\n\n", cdd[y].info);
								printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
								scanf("%d", &op);
								system("cls");
							}
							if(campo==5){
								printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
								fflush(stdin);
								gets(regs);
								strcpy(cdd[y].info, regs);
								system("cls");
								printf("\t########################################\n\n");
								printf("\tnome da empresa: %s\n", cdd[y].nome_empre);
								printf("\tCNPJ: %d\n", cdd[y].cnpj);
								printf("\tnome: %s\n", cdd[y].nome_prop);
								printf("\tlocal de alocação: %s\n", cdd[y].local);
								printf("\tvalor da alocação: %0.2f\n", cdd[y].valor);
								printf("\tinformações:\n \t%s\n\n", cdd[y].info);
								printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
								scanf("%d", &op);
								system("cls");
							}
							if(campo==6){
								printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
								fflush(stdin);
								scanf("%f", &regf);
								cdd[y].valor=regf;
								system("cls");
								printf("\t########################################\n\n");
								printf("\tnome da empresa: %s\n", cdd[y].nome_empre);
								printf("\tCNPJ: %d\n", cdd[y].cnpj);
								printf("\tnome: %s\n", cdd[y].nome_prop);
								printf("\tlocal de alocação: %s\n", cdd[y].local);
								printf("\tvalor da alocação: %0.2f\n", cdd[y].valor);
								printf("\tinformações:\n \t%s\n\n", cdd[y].info);
								printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
								scanf("%d", &op);
								system("cls");
							}
						}while(op==1);
						n=remove("ark.txt");
						arq=fopen("ark.txt", "a+");
						if(arq==NULL){
							printf("\n\tErro na abertura do arquivo.\n");
							system("pause");
							exit(1);
						}
						fflush(stdin);
						fflush(arq);
						fwrite (&cdd, sizeof(struct cadastro), j/224, arq);
						if(fwrite != 0){ 
					    	printf("\tDados salvos com sucesso!\n"); 
					    	system("pause");
					    	system("cls");
					   	}
					   	else{
					    	printf("\tErro ao salvar.\n");
					    	system("pause");
					    	system("cls");
					    }
					    fclose(arq);
					    fflush(arq);
					    return 0;
					}
			return 0;
		}
		else if(opp==2){ // se a opção for reativar cadastro;
			printf("\n\tFavor informe o CNPJ da empresa a ser reativado no sistema: ");
			fflush(stdin);
			scanf("%d", &cnpj);
			system("cls");
			printf("\n\tPor favor confira os dados abaixo:");
			for(i=0;i<j/224;i++){
				if(cnpj==cdd[i].cnpj){
					printf("\n\t###################################\n");
					printf("\n\tID: %d", cdd[i].id);
					printf("\n\tEmpresa: %s", cdd[i].nome_empre);
					printf("\n\tCNPJ: %d", cdd[i].cnpj);
					printf("\n\tProprietário: %s", cdd[i].nome_prop);
					printf("\n\tLocal: %s", cdd[i].local);
					printf("\n\tAluguel: %0.2f", cdd[i].valor);
					printf("\n\tInformações: %s", cdd[i].info);
					printf("\n\tStatus: %s", cdd[i].status);
					printf("\n\n");
					printf("\n\tDeseja confirmar reativação?(s/n)");
					fflush(stdin);
					scanf("%s", &p);
					if(p=='s'||p=='S'){
						strcpy(cdd[i].status, "Ativo"); // fazendo o inverso da desativação, ao invés de sobreescrever desativado sobreescreve Ativo;
						n=remove("ark.txt"); // removedo o arquivo;
						arq=fopen("ark.txt", "a+"); // recriando o arquivo com o mesmo nome;
						if(arq==NULL){
							printf("\n\tErro na abertura do arquivo.\n");
							system("pause");
							exit(1);
						}
						fflush(stdin);
						fflush(arq);
						fwrite (&cdd, sizeof(struct cadastro), j/224, arq); // escrevendo novamente todos os registros;
						if(fwrite != 0){ 
					    	printf("\n\n\n\tDados salvos com sucesso!\n"); 
					    	system("pause");
					    	system("cls");
					   	}
					   	else{
					    	printf("\tErro ao salvar.\n");
					    	system("pause");
					    	system("cls");
					    }
					    fclose(arq);
					    fflush(arq);
					    return 0;
					}
					else{
						return 0;
					}
				}
			}
		}
}

int gerenciar(int op){ // função para chamar outras funções para gerenciameto dos registros do arquivo.
	
	int retorno=0;
	
	if(op==1){ // se o parâmetro trazido for 1 chama a função desative para desativar um cadastro.
		retorno=desative();
	}
	else if(op==2){ // se o parâmetro trazido for 2 chama a função edit para editar dados de um cadastro ou ativar um cadastro inativo.
		retorno=edit();
	}
	else if(op!=1&&op!=2){
		return retorno;
	}
}
 
int cad (char op) // função para cadastrar novo locatário;
{
	int c=0, resp=0, i=0, campo=0, n=0;
	float regf=0;
	char regs[50];
	FILE *arq;
	
	system("cls");
	
	struct cadastro ca;
	
	do{	// laço para preenchimento do cadastro;
		printf("\n\tFavor informar os dados do locatario:\n");
		printf("\t#########################################");
		printf("\n\tInforme o nome da empresa: ");
		fflush(stdin);
		gets(ca.nome_empre);
		printf("\n\tInforme o CNPJ da empresa: ");
		fflush(stdin);
		scanf("%d", &ca.cnpj);	
		printf("\n\tInforme o nome do proprietario: ");
		fflush(stdin);
		gets(ca.nome_prop);
		printf("\n\tInforme o local da locação: ");
		fflush(stdin);
		gets(ca.local);
		printf("\n\tInforme o valor da locação: ");
		scanf("%f", &ca.valor);
		printf("\n\tPreencha com informações:\n");
		fflush(stdin);
		gets(ca.info);
		system("cls");
		ca.id=i;	
		printf("\n\tPor favor confira os dados:");
		printf("\t########################################\n\n");
		printf("\tnome da empresa: %s\n", ca.nome_empre);
		printf("\tCNPJ: %d\n", ca.cnpj);
		printf("\tnome: %s\n", ca.nome_prop);
		printf("\tlocal de alocação: %s\n", ca.local);
		printf("\tvalor da alocação: %0.2f\n", ca.valor);
		printf("\tinformações:\n \t%s\n\n", ca.info);
		printf("\n\tDeseja fazer alguma alteração?(s/n)\n");
		fflush(stdin);
		scanf("%s", &op);
		system("cls");
		if(op=='s'||op=='S'){
			do{ // laço para fazer edições que o usuário julgar necessárias antes de registrar no arquivo.
				printf("\n\tInforme o campo a ser modificado: ");
				printf("\n\t1 - Empresa");
				printf("\n\t2 - CNPJ");
				printf("\n\t3 - Proprietário");
				printf("\n\t4 - Local");
				printf("\n\t5 - Informações");
				printf("\n\t6 - Valor\n");
				fflush(stdin);
				scanf("%d", &campo);
				
				// a edição é feita campo por campo, para não precisar preencher todos novamente.
				if(campo==1){
					printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
					fflush(stdin);
					gets(regs);
					strcpy(ca.nome_empre, regs);
					system("cls");
					printf("\t########################################\n\n");
					printf("\tnome da empresa: %s\n", ca.nome_empre);
					printf("\tCNPJ: %d\n", ca.cnpj);
					printf("\tnome: %s\n", ca.nome_prop);
					printf("\tlocal de alocação: %s\n", ca.local);
					printf("\tvalor da alocação: %0.2f\n", ca.valor);
					printf("\tinformações:\n \t%s\n\n", ca.info);
					printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
					scanf("%d", &op);
					system("cls");
				}
				if(campo==2){
					printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
					fflush(stdin);
					scanf("%f", &regf);
					ca.cnpj=regf;
					system("cls");
					printf("\t########################################\n\n");
					printf("\tnome da empresa: %s\n", ca.nome_empre);
					printf("\tCNPJ: %d\n", ca.cnpj);
					printf("\tnome: %s\n", ca.nome_prop);
					printf("\tlocal de alocação: %s\n", ca.local);
					printf("\tvalor da alocação: %0.2f\n", ca.valor);
					printf("\tinformações:\n \t%s\n\n", ca.info);
					printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
					scanf("%d", &op);
					system("cls");
				}
				if(campo==3){
					printf("\n\tPor favor entre com o novo dado a ser inserido no campo: ");
					fflush(stdin);
					gets(regs);
					strcpy(ca.nome_prop, regs);
					system("cls");
					printf("\t########################################\n\n");
					printf("\tnome da empresa: %s\n", ca.nome_empre);
					printf("\tCNPJ: %d\n", ca.cnpj);
					printf("\tnome: %s\n", ca.nome_prop);
					printf("\tlocal de alocação: %s\n", ca.local);
					printf("\tvalor da alocação: %0.2f\n", ca.valor);
					printf("\tinformações:\n \t%s\n\n", ca.info);
					printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
					scanf("%d", &op);
					system("cls");
				}
				if(campo==4){
					printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
					fflush(stdin);
					gets(regs);
					strcpy(ca.local, regs);
					system("cls");
					printf("\t########################################\n\n");
					printf("\tnome da empresa: %s\n", ca.nome_empre);
					printf("\tCNPJ: %d\n", ca.cnpj);
					printf("\tnome: %s\n", ca.nome_prop);
					printf("\tlocal de alocação: %s\n", ca.local);
					printf("\tvalor da alocação: %0.2f\n", ca.valor);
					printf("\tinformações:\n \t%s\n\n", ca.info);
					printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
					scanf("%d", &op);
					system("cls");
				}
				if(campo==5){
					printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
					fflush(stdin);
					gets(regs);
					strcpy(ca.info, regs);
					system("cls");
					printf("\t########################################\n\n");
					printf("\tnome da empresa: %s\n", ca.nome_empre);
					printf("\tCNPJ: %d\n", ca.cnpj);
					printf("\tnome: %s\n", ca.nome_prop);
					printf("\tlocal de alocação: %s\n", ca.local);
					printf("\tvalor da alocação: %0.2f\n", ca.valor);
					printf("\tinformações:\n \t%s\n\n", ca.info);
					printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
					scanf("%d", &op);
					system("cls");
				}
				if(campo==6){
					printf("\n\tPor favor entre com o novo valor a ser inserido no campo: ");
					fflush(stdin);
					scanf("%f", &regf);
					ca.valor=regf;
					system("cls");
					printf("\t########################################\n\n");
					printf("\tnome da empresa: %s\n", ca.nome_empre);
					printf("\tCNPJ: %d\n", ca.cnpj);
					printf("\tnome: %s\n", ca.nome_prop);
					printf("\tlocal de alocação: %s\n", ca.local);
					printf("\tvalor da alocação: %0.2f\n", ca.valor);
					printf("\tinformações:\n \t%s\n\n", ca.info);
					printf("\n\tDeseja modificar outro campo?(1 - Sim||2 - Não)\n");
					scanf("%d", &op);
					system("cls");
				}
			}while(op==1); // o laço para edição se repete até que o usuário digite a opção 2 quando perguntado se quer alterar outro campo.
		} // se o usuário não quer editar nenhum campo então:
		  // este procedimento abaixo é para registrar os cadastros no arquivo.
		system("cls");
		i=i+1;
		strcpy(ca.status, "Ativo");
		restidi(&i); // chamando função para comparar o 'i' com o maior ID registrado no arquivo; 
		ca.id=i;
		arq=fopen("ark.txt", "a+"); // abrindo arquivo para escrita e adição de registro;
		if(arq==NULL){
			printf("\n\tErro na abertura do arquivo.\n");
			system("pause");
			exit(1);
		}
		fflush(stdin);
		fflush(arq);
		fwrite (&ca, sizeof(struct cadastro), 1, arq);
		if(fwrite != 0){ 
	    	printf("\tDados salvos com sucesso!\n"); 
	    	system("pause");
	    	system("cls");
	   	}
	   	else{
	    	printf("\tErro o salvar.\n");
	    	system("pause");
	    	system("cls");
	    }
	    fclose(arq);
	    fflush(arq);
	    fflush(stdin);
	    printf("\n\tDeseja cadastrar outro locatário?(s/n)\n");
		fflush(stdin);
		scanf("%s", &op);
	}while(op=='s'||op=='S'); // o laço de preenchimento de cadastro se repete até que o usuário digite n ou N  para a pergunta 'deseja cadastrar outro locatário?'.
	return c; // a variável c foi declarada como int nesta função e inicializada com 0, portanto quando ela retornar fará com que o menu principal seja chamado;				  
}

int menulist() // MENU PARA OPÇÕES DO ARQUIVO;
 {
 	int sel=0, op=0;
 	struct cadastro cd;
 	FILE *arq;
 	
 	printf ("\t   ________________________________________________________________________________________________________\n");
	printf ("\t  |                                                                                                        |\n");
	printf ("\t  |      ###   ###  #####  ##   #  #   #       ####    #####    #####    #   #  #  #   #   #####           |\n");
	printf ("\t  |      #  # #  #  #___   # #  #  #   #      #    #   #    #  #     #   #   #  #  #   #  #     #          |\n");
	printf ("\t  |      #   #   #  #      #  # #  #   #      # ## #   #  #    #   ###   #   #  #   # #   #     #          |\n");
	printf ("\t  |      #       #  #####  #   ##  #####      #    #   #    #   ##### #  #####  #    #     #####           |\n");
	printf ("\t  |________________________________________________________________________________________________________|\n\n");
	
	printf ("\t   ________________________________________________________________________________________________________\n");
	printf ("\t  |                                                                                                        |\n");
	printf ("\t  |            1 ->  Arquivo de locatários                                                                 |\n");
	printf ("\t  |            2 ->  Listagem Ordenada		                                                           |\n");
	printf ("\t  |            3 ->  Consulta Individual                                                                   |\n");
	printf ("\t  |            0 ->  Voltar                                                                                |\n");
	printf ("\t  |________________________________________________________________________________________________________|\n\n");
	printf("\n");
	printf ("\n\tPOR FAVOR DIGITE A OPÇÃO DESEJADA:\n");
	scanf("%d", &sel);
	system("cls"); 	
	if(sel==0){
		return sel;
	}
	switch(sel){
		case 1: // abrindo o arquivo e printando diretamente para mostrar todos os registros existentes;
			arq=fopen("ark.txt", "rb"); // abrindo para leitura;
		    while(fread(&cd, sizeof(struct cadastro), 1, arq))
		    printf ("\t**\n\tid: %d\n\tEmpresa: %s\n\tCNPJ: %d\n\tProprietáro: %s\n\tLocação: %s\n\tMensalidade: %0.2f\n\tInfo:%s\n\tStatus: %s\n\n\n", 
			cd.id, cd.nome_empre, cd.cnpj, cd.nome_prop, cd.local, cd.valor, cd.info, cd.status); 
		    fclose(arq);
		    system("pause");
		    system("cls");
			break;
		case 2: // opção para mostrar lista ordenado; 
			printf("\t#########################################");
			printf("\n\t1 - Listar por Nome\n");
			printf("\n\t2 - Listar por CNPJ\n");	
			printf("\t#########################################\n");		
			scanf("%d", &op);
			system("cls");
			sel=consul(op); // chamando função para chamada das funções de ordenação, levado a opção digitada como parâmetro;
			system("cls");
			break;
		case 3: // opção para consultar um locatário específico;
			printf("\t#########################################");
			printf("\n\t1 - Consultar por Nome\n");
			printf("\n\t2 - Consultar por CNPJ\n");	
			printf("\t#########################################\n");		
			scanf("%d", &op);
			system("cls");
			sel=searchcad(op); // chamando função para pesquisar um locatário, levando opção digitada como parâmetro; 
			break;
		case 0:
			return sel; // retorna o 0 registrado no sel para o menu principal.
			break;
		default:
			printf("\n\tOpção Inválida.");
			Sleep(1200);
			sel=0;
			return sel; // se a opção é inválida retorna ao menu principal.
			break;
	}	
}
 
 
