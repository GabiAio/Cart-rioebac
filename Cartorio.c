#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro () //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string (conjunto de variáveis)
	char arquivo[40]; //char variável que representa um caractere do tipo texto ou número
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo "a" (append), que adiciona conteúdo ao final do arquivo sem apagar o anterior
	fprintf(file,","); // Escreve uma vírgula no arquivo para separar os campos
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Solicita o nome do usuário
	scanf("%s", nome); // Lê a string digitada pelo usuário e armazena na variável 'nome'
	
	file = fopen(arquivo, "a"); // Abre o arquivo novamente para adicionar o nome coletado
	fprintf(file,nome); // Escreve o conteúdo da variável 'nome' dentro do arquivo
	fclose(file); // Fecha o arquivo após a escrita do nome
	
	file = fopen(arquivo, "a"); // Escreve uma vírgula no arquivo após o nome
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // Solicita o sobrenome ao usuário
	scanf("%s", sobrenome); // Armazena o sobrenome digitado na variável 'sobrenome'
	
	file = fopen(arquivo, "a"); // Abre o arquivo para anexar o sobrenome
	fprintf(file,sobrenome);
	fclose(file); // Fecha o arquivo após salvar o sobrenome
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adicionar mais uma vírgula antes do cargo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // Solicita o cargo ao usuário
	scanf("%s",cargo); // Armazena o cargo digitado na variável 'cargo'
	
	file = fopen(arquivo, "a"); // Abre o arquivo para salvar o cargo
	fprintf(file,cargo); 
    fclose(file); // Fecha o arquivo finalizando a operação de escrita
	
	system("pause");
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
	
}

int deletar ()
{
	char cpf[40];
	
	printf ("Digite o CPF do usuário a ser deletado:");
	scanf ("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:"); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
    
    	system("cls"); //responsável por limpar a tela
    	
    	switch(opcao) //Inicio da seleção do menu
    	{
    		case 1:
    	    registro (); //chamada de funções
			break;	
			
			case 2:
   	 		consulta ();
			break;
			
			case 3:
			deletar ();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;	
			//fim da seleção	
		}
    
    
    }
	
	
}
	
	

