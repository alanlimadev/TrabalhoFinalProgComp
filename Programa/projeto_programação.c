#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

char questoes[20][100] = {"Histórico da Computação",
	"Arquitetura Básica","Sistemas de Numeração",
	"Lógica de Programação","Pseudocódigo",
	"Fluxogramas","Sintaxe da Linguagem C","Variáveis",
	"Funções de Entrada e Saída","Estruturas Condicionais em C",
	"Comandos de Repetição em C","Comandos de Controle de Fluxo", 
	"Vetores","Matrizes","Strings","Structs e Typedef",
	"Ponteiros","Malloc / Calloc / Free","Funções","Arquivos"};
	
	typedef struct questao{
		int indice;
		char tema[100];
	}Questao;
	
	Questao banco[10];
	
	typedef struct dificuldade{
		int nivel;
	}Dificuldade;
	
	Dificuldade bancoNivel [10];
	
	typedef struct aluno{
		int indice;
		char nome[100];
		int notas[10];
	}Aluno;
	
int main(void){
	int qalunos, quantquest;
	
	setlocale(LC_ALL, "Portuguese");
	printf("A SEGUIR O PROGRAMA DE AVALIAÇÃO DE TURMA\n\nLEMBRETE: \n1 - Leia primeira a documentação do projeto para utilizar.\n2 - Você tem a limitação de escolher no máximo 10 questões.\n\n");
	
	//declaração da função responsável pelo cadastro das questões.
	void cadQuestoes();
	
	//seleção da quantidade de questões desejadas para a sua prova.
	do{
		printf("Informe quantas questões terá na sua prova: ");
		scanf("%d", &quantquest);
		
		if(quantquest>10 || quantquest<1)
			printf("\nAVISO: Informe uma quantidade de questões maior que 0 e menor que 11.\n\n");
	}while(quantquest>10 || quantquest<1);
	
	/*função responsável pelo cadastro das questões, informando
	quais os temas referentes a cada questão e a dificuldade de 
	cada questão selecionada.*/
	cadQuestoes(quantquest);	
	
	//declaração da função responsável pelo cadastro dos alunos.
	void cadAluno();
	
	//seleção da quantidade de alunos que realizaram a avaliação.
	printf("Informe a quantidade de alunos que realizaram a prova: ");
	scanf("%d", &qalunos);
	//vetor de estrutura responsável por armazenar os dados de cada aluno.
	Aluno dados [qalunos];
	
	/*função responsável pelo cadastro dos dados de cada aluno, informando
	o nome de cada aluno e os acertos/erros de cada aluno em cada questão.*/
	cadAluno(dados, qalunos,quantquest);
	
	//declaração da função responsável por informar a análise geral da turma (porcentagem de acertos/erros).
	void acertoErro();
	
	acertoErro(dados,quantquest,qalunos);
	
	//declaração da função responsável por informar a análise geral da turma (desempenho).
	void condicaoTurma();
	
	condicaoTurma(dados, quantquest, qalunos);
	
	return 0;
}

void cadQuestoes(int quantquest){
	int i;
	system("cls");
	
	printf("Assuntos do primeiro semestre de programação: \n\n");
	
	for(i = 0; i<20; i++)
		printf("%d. %s\n", i, questoes[i]);
	
	printf("\n");
	
	for(i = 0; i<quantquest; i++){
		do{
			printf("\nATENÇÃO: Informe a numeração referente a %dª questão: ", i + 1);
			scanf("%d", &banco[i].indice);
		
			if(banco[i].indice>19 || banco[i].indice<0){
				printf("\nAVISO: Informe uma numeração válida.\n");
				//exit(0);
			}		
		}while(banco[i].indice>19 || banco[i].indice<0);
		strcpy(banco[i].tema, questoes[banco[i].indice]);
	}
	
	printf("\n");
	system("pause");
	system("cls");
	
	printf("LEMBRETE:\n\nDigite:\n1 se a questão possuir nível fácil;\n2 se a questão possuir nível médio;\n3 se a questão possuir nível difícil.\n\n");
	
	for(i = 0; i < quantquest; i++){
		do{
			printf("Selecione a dificuldade da %dª questão sobre %s: ", i + 1,banco[i].tema);
			scanf("%d", &bancoNivel[i].nivel);		
			
			if(bancoNivel[i].nivel<1 || bancoNivel[i].nivel>3)
				printf("\nDIGITE UM VALOR VÁLIDO.\n\n");
						
		}while(bancoNivel[i].nivel<1 || bancoNivel[i].nivel>3);
		
		printf("\n");
		
	}
	
	printf("\n");
	system("pause");
	system("cls");
	
	printf("LEIA COM MUITA ATENÇÃO!\n\n");
	
	for(i = 0; i < quantquest; i++){
		switch (bancoNivel[i].nivel){
			case 1:
				printf("Você definiu a %dª questão sobre %s como FÁCIL.\n", i + 1, banco[i].tema);
				break;
			case 2:
				printf("Você definiu a %dª questão sobre %s como MÉDIA.\n", i + 1, banco[i].tema);				
				break;
			case 3:
				printf("Você definiu a %dª questão sobre %s como DÍFICIL.\n", i + 1, banco[i].tema);				
				break;
		}
	}
	
	printf("\n");
	system("pause");
	system("cls");
}

void cadAluno(Aluno dados[],int qalunos,int quantquest){
	int i, j;
	printf("\n");
	system("pause");
	system("cls");	
	
	for(i = 0; i < qalunos; i++){
		dados[i].indice = i+1;
		
		printf("Informe o nome do aluno número %d: ", dados[i].indice);
		
		scanf(" %[^\n]s", dados[i].nome);				
	}

	printf("\n");
	system("pause");	
	system("cls");
	
	printf("LEMBRETE:\n\nDigite:\n1 se o aluno acertou a questão;\n0 se o aluno errou a questão.\n\n");
	
	for(i = 0; i < qalunos; i++){
		
			printf("ATENÇÃO: Informe o Gabarito de %s.\n", dados[i].nome);
			for(j = 0; j < quantquest; j++){
				//laço de repetição pra aceitar só 0 e 1
				do{
					printf("Informe se %s acertou ou errou a %dª questão sobre %s: ", dados[i].nome, j + 1, banco[j].tema);
					scanf("%d", &dados[i].notas[j]);
	
					if(dados[i].notas[j] < 0 || dados[i].notas[j] > 1)
						printf("\nDIGITE UM VALOR VÁLIDO.\n\n");
				
				}while(dados[i].notas[j] < 0 || dados[i].notas[j] > 1);	
			}
			printf("\n");			
	}

	printf("\n");
	system("pause");
	system("cls");
}

void acertoErro(Aluno dados[], int quantquest,int qalunos){
	float varaux1, varaux2;
	int i,j;
	
	printf("ANÁLISE GERAL DA TURMA: PERCENTUAL DE ACERTOS EM CADA QUESTÃO\n\n");
	
	for(i = 0; i < quantquest; i++){
		varaux1 = 0;
		for(j = 0; j < qalunos; j++){
			varaux1 += dados[j].notas[i];
		}
		varaux1 = varaux1 / (float) qalunos;
		varaux1 *= 100;
		varaux2 = 100 - varaux1;			
		printf("QUESTÃO %d - %s\nPercentual de Acertos/Erros: %.2f%% / %.2f%%.\n\n", i + 1, banco[i].tema, varaux1, varaux2);
	}
	
	printf("-------------------------------------------------------------\n");
}

void condicaoTurma(Aluno dados[], int quantquest,int qalunos){
	float varaux1, varaux2;
	int i,j;
	
	printf("\nANÁLISE GERAL DA TURMA: CONDIÇÃO DA TURMA\n\n");
	
	for(i = 0; i < quantquest; i++){
		varaux1 = 0;
		for(j = 0; j < qalunos; j++){
			varaux1 += dados[j].notas[i];
		}
		varaux1 = varaux1 / (float) qalunos;
		varaux1 *= 100;
		
		switch(bancoNivel[i].nivel){
				case 1:
					if(varaux1 >= 75){
						printf("QUESTÃO %d - %s => FÁCIL\nDesempenho da Turma: ÓTIMO\n\n", i + 1,banco[i].tema);	
					} 
					if(varaux1 >= 60 && varaux1 < 75){
						printf("QUESTÃO %d - %s => FÁCIL\nDesempenho da Turma: BOM\n\n", i + 1,banco[i].tema);	
					}		
					if(varaux1 >= 45 && varaux1 < 60){
						printf("QUESTÃO %d - %s => FÁCIL\nDesempenho da Turma: REGULAR\n\n", i + 1,banco[i].tema);	
					}
					if(varaux1 >= 30 && varaux1 < 45){
						printf("QUESTÃO %d - %s => FÁCIL\nDesempenho da Turma: RUIM\n\n", i + 1, banco[i].tema);		
					}
					if(varaux1 < 30){
						printf("QUESTÃO %d - %s => FÁCIL\nDesempenho da Turma: CRÍTICO\n\n", i + 1, banco[i].tema);		
					}				
					break;	
				case 2:
					if(varaux1 >= 60){
						printf("QUESTÃO %d - %s => MÉDIO\nDesempenho da Turma: ÓTIMO\n\n", i + 1, banco[i].tema);	
					} 
					if(varaux1 >= 45 && varaux1 < 60){
						printf("QUESTÃO %d - %s => MÉDIO\nDesempenho da Turma: BOM\n\n", i + 1, banco[i].tema);	
					}				
					if(varaux1 >= 35 && varaux1 < 45){
						printf("QUESTÃO %d - %s => MÉDIO\nDesempenho da Turma: REGULAR\n\n", i + 1, banco[i].tema);	
					}				
					if(varaux1 >= 20 && varaux1 < 35){
						printf("QUESTÃO %d - %s => MÉDIO\nDesempenho da Turma: RUIM\n\n", i + 1, banco[i].tema);	
					}	
					if(varaux1 < 20){
						printf("QUESTÃO %d - %s => MÉDIO\nDesempenho da Turma: CRÍTICO\n\n", i + 1, banco[i].tema);	
					}				
					break;
				case 3:
					if(varaux1 >= 45){
						printf("QUESTÃO %d - %s => DIFÍCIL\nDesempenho da Turma: ÓTIMO\n\n", i + 1, banco[i].tema);	
					} 
					if(varaux1 >= 35 && varaux1 < 45){
						printf("QUESTÃO %d - %s => DIFÍCIL\nDesempenho da Turma: BOM\n\n", i + 1, banco[i].tema);	
					}
					if(varaux1 >= 20 && varaux1 < 35){
						printf("QUESTÃO %d - %s => DIFÍCIL\nDesempenho da Turma: REGULAR\n\n", i + 1, banco[i].tema);	
					}
					if(varaux1 >= 15 && varaux1 < 20){
						printf("QUESTÃO %d - %s => DIFÍCIL\nDesempenho da Turma: RUIM\n\n", i + 1, banco[i].tema);		
					}				
					if(varaux1 < 15){
						printf("QUESTÃO %d - %s => DIFÍCIL\nDesempenho da Turma: CRÍTICO\n\n", i + 1, banco[i].tema);	
					}				
					break;											
		}
	}
}
