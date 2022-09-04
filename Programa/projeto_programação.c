#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

char questoes[20][100] = {"Hist�rico da Computa��o",
	"Arquitetura B�sica","Sistemas de Numera��o",
	"L�gica de Programa��o","Pseudoc�digo",
	"Fluxogramas","Sintaxe da Linguagem C","Vari�veis",
	"Fun��es de Entrada e Sa�da","Estruturas Condicionais em C",
	"Comandos de Repeti��o em C","Comandos de Controle de Fluxo", 
	"Vetores","Matrizes","Strings","Structs e Typedef",
	"Ponteiros","Malloc / Calloc / Free","Fun��es","Arquivos"};
	
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
	printf("A SEGUIR O PROGRAMA DE AVALIA��O DE TURMA\n\nLEMBRETE: \n1 - Leia primeira a documenta��o do projeto para utilizar.\n2 - Voc� tem a limita��o de escolher no m�ximo 10 quest�es.\n\n");
	
	//declara��o da fun��o respons�vel pelo cadastro das quest�es.
	void cadQuestoes();
	
	//sele��o da quantidade de quest�es desejadas para a sua prova.
	do{
		printf("Informe quantas quest�es ter� na sua prova: ");
		scanf("%d", &quantquest);
		
		if(quantquest>10 || quantquest<1)
			printf("\nAVISO: Informe uma quantidade de quest�es maior que 0 e menor que 11.\n\n");
	}while(quantquest>10 || quantquest<1);
	
	/*fun��o respons�vel pelo cadastro das quest�es, informando
	quais os temas referentes a cada quest�o e a dificuldade de 
	cada quest�o selecionada.*/
	cadQuestoes(quantquest);	
	
	//declara��o da fun��o respons�vel pelo cadastro dos alunos.
	void cadAluno();
	
	//sele��o da quantidade de alunos que realizaram a avalia��o.
	printf("Informe a quantidade de alunos que realizaram a prova: ");
	scanf("%d", &qalunos);
	//vetor de estrutura respons�vel por armazenar os dados de cada aluno.
	Aluno dados [qalunos];
	
	/*fun��o respons�vel pelo cadastro dos dados de cada aluno, informando
	o nome de cada aluno e os acertos/erros de cada aluno em cada quest�o.*/
	cadAluno(dados, qalunos,quantquest);
	
	//declara��o da fun��o respons�vel por informar a an�lise geral da turma (porcentagem de acertos/erros).
	void acertoErro();
	
	acertoErro(dados,quantquest,qalunos);
	
	//declara��o da fun��o respons�vel por informar a an�lise geral da turma (desempenho).
	void condicaoTurma();
	
	condicaoTurma(dados, quantquest, qalunos);
	
	return 0;
}

void cadQuestoes(int quantquest){
	int i;
	system("cls");
	
	printf("Assuntos do primeiro semestre de programa��o: \n\n");
	
	for(i = 0; i<20; i++)
		printf("%d. %s\n", i, questoes[i]);
	
	printf("\n");
	
	for(i = 0; i<quantquest; i++){
		do{
			printf("\nATEN��O: Informe a numera��o referente a %d� quest�o: ", i + 1);
			scanf("%d", &banco[i].indice);
		
			if(banco[i].indice>19 || banco[i].indice<0){
				printf("\nAVISO: Informe uma numera��o v�lida.\n");
				//exit(0);
			}		
		}while(banco[i].indice>19 || banco[i].indice<0);
		strcpy(banco[i].tema, questoes[banco[i].indice]);
	}
	
	printf("\n");
	system("pause");
	system("cls");
	
	printf("LEMBRETE:\n\nDigite:\n1 se a quest�o possuir n�vel f�cil;\n2 se a quest�o possuir n�vel m�dio;\n3 se a quest�o possuir n�vel dif�cil.\n\n");
	
	for(i = 0; i < quantquest; i++){
		do{
			printf("Selecione a dificuldade da %d� quest�o sobre %s: ", i + 1,banco[i].tema);
			scanf("%d", &bancoNivel[i].nivel);		
			
			if(bancoNivel[i].nivel<1 || bancoNivel[i].nivel>3)
				printf("\nDIGITE UM VALOR V�LIDO.\n\n");
						
		}while(bancoNivel[i].nivel<1 || bancoNivel[i].nivel>3);
		
		printf("\n");
		
	}
	
	printf("\n");
	system("pause");
	system("cls");
	
	printf("LEIA COM MUITA ATEN��O!\n\n");
	
	for(i = 0; i < quantquest; i++){
		switch (bancoNivel[i].nivel){
			case 1:
				printf("Voc� definiu a %d� quest�o sobre %s como F�CIL.\n", i + 1, banco[i].tema);
				break;
			case 2:
				printf("Voc� definiu a %d� quest�o sobre %s como M�DIA.\n", i + 1, banco[i].tema);				
				break;
			case 3:
				printf("Voc� definiu a %d� quest�o sobre %s como D�FICIL.\n", i + 1, banco[i].tema);				
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
		
		printf("Informe o nome do aluno n�mero %d: ", dados[i].indice);
		
		scanf(" %[^\n]s", dados[i].nome);				
	}

	printf("\n");
	system("pause");	
	system("cls");
	
	printf("LEMBRETE:\n\nDigite:\n1 se o aluno acertou a quest�o;\n0 se o aluno errou a quest�o.\n\n");
	
	for(i = 0; i < qalunos; i++){
		
			printf("ATEN��O: Informe o Gabarito de %s.\n", dados[i].nome);
			for(j = 0; j < quantquest; j++){
				//la�o de repeti��o pra aceitar s� 0 e 1
				do{
					printf("Informe se %s acertou ou errou a %d� quest�o sobre %s: ", dados[i].nome, j + 1, banco[j].tema);
					scanf("%d", &dados[i].notas[j]);
	
					if(dados[i].notas[j] < 0 || dados[i].notas[j] > 1)
						printf("\nDIGITE UM VALOR V�LIDO.\n\n");
				
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
	
	printf("AN�LISE GERAL DA TURMA: PERCENTUAL DE ACERTOS EM CADA QUEST�O\n\n");
	
	for(i = 0; i < quantquest; i++){
		varaux1 = 0;
		for(j = 0; j < qalunos; j++){
			varaux1 += dados[j].notas[i];
		}
		varaux1 = varaux1 / (float) qalunos;
		varaux1 *= 100;
		varaux2 = 100 - varaux1;			
		printf("QUEST�O %d - %s\nPercentual de Acertos/Erros: %.2f%% / %.2f%%.\n\n", i + 1, banco[i].tema, varaux1, varaux2);
	}
	
	printf("-------------------------------------------------------------\n");
}

void condicaoTurma(Aluno dados[], int quantquest,int qalunos){
	float varaux1, varaux2;
	int i,j;
	
	printf("\nAN�LISE GERAL DA TURMA: CONDI��O DA TURMA\n\n");
	
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
						printf("QUEST�O %d - %s => F�CIL\nDesempenho da Turma: �TIMO\n\n", i + 1,banco[i].tema);	
					} 
					if(varaux1 >= 60 && varaux1 < 75){
						printf("QUEST�O %d - %s => F�CIL\nDesempenho da Turma: BOM\n\n", i + 1,banco[i].tema);	
					}		
					if(varaux1 >= 45 && varaux1 < 60){
						printf("QUEST�O %d - %s => F�CIL\nDesempenho da Turma: REGULAR\n\n", i + 1,banco[i].tema);	
					}
					if(varaux1 >= 30 && varaux1 < 45){
						printf("QUEST�O %d - %s => F�CIL\nDesempenho da Turma: RUIM\n\n", i + 1, banco[i].tema);		
					}
					if(varaux1 < 30){
						printf("QUEST�O %d - %s => F�CIL\nDesempenho da Turma: CR�TICO\n\n", i + 1, banco[i].tema);		
					}				
					break;	
				case 2:
					if(varaux1 >= 60){
						printf("QUEST�O %d - %s => M�DIO\nDesempenho da Turma: �TIMO\n\n", i + 1, banco[i].tema);	
					} 
					if(varaux1 >= 45 && varaux1 < 60){
						printf("QUEST�O %d - %s => M�DIO\nDesempenho da Turma: BOM\n\n", i + 1, banco[i].tema);	
					}				
					if(varaux1 >= 35 && varaux1 < 45){
						printf("QUEST�O %d - %s => M�DIO\nDesempenho da Turma: REGULAR\n\n", i + 1, banco[i].tema);	
					}				
					if(varaux1 >= 20 && varaux1 < 35){
						printf("QUEST�O %d - %s => M�DIO\nDesempenho da Turma: RUIM\n\n", i + 1, banco[i].tema);	
					}	
					if(varaux1 < 20){
						printf("QUEST�O %d - %s => M�DIO\nDesempenho da Turma: CR�TICO\n\n", i + 1, banco[i].tema);	
					}				
					break;
				case 3:
					if(varaux1 >= 45){
						printf("QUEST�O %d - %s => DIF�CIL\nDesempenho da Turma: �TIMO\n\n", i + 1, banco[i].tema);	
					} 
					if(varaux1 >= 35 && varaux1 < 45){
						printf("QUEST�O %d - %s => DIF�CIL\nDesempenho da Turma: BOM\n\n", i + 1, banco[i].tema);	
					}
					if(varaux1 >= 20 && varaux1 < 35){
						printf("QUEST�O %d - %s => DIF�CIL\nDesempenho da Turma: REGULAR\n\n", i + 1, banco[i].tema);	
					}
					if(varaux1 >= 15 && varaux1 < 20){
						printf("QUEST�O %d - %s => DIF�CIL\nDesempenho da Turma: RUIM\n\n", i + 1, banco[i].tema);		
					}				
					if(varaux1 < 15){
						printf("QUEST�O %d - %s => DIF�CIL\nDesempenho da Turma: CR�TICO\n\n", i + 1, banco[i].tema);	
					}				
					break;											
		}
	}
}
