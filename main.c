//CRUD Sistema de cadastro 
//Candidatos ENEM
//versão 1.0.0
//O projeto visa desenvolver um programa em linguagem c capaz de armazenar e consultar dados em arquivos/streams - armazenamento secundário.
//O pragrama será composto primordialmente por um menu de opções, sendo:
//a)cadastrar pessoa
//b)Cadastrar estado
//c)Cadastrar curso
//d)Listar pessoas por estado
//e)Listar pessoa por curso desejado
//f)Consultar pessoa por nome
//g)Gerar relatório demográfico
//h)finalizar programa
//cada item realizado por um procedimento específico
//De acordo com as políticas de entrega de atividades repassadas pelo professor, certifico que os algoritmos e programas que estou entregando são de minha autoria e que não os repassei ou os recebi de qualquer outra pessoa.
//Por Jackes Tiago Ferreira da Fonseca 19/0030291

//declaração de constantes
//importação de arquivos de cabeçalho
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define MAX 50
#define MIN 20

//estrutura principal para cadastro de dados;
typedef struct candidato{
	char nome[MAX], sexo[MAX];
	char curso[MAX];
	char data_nascimento[MAX];
	char estado[MAX], unidade_federacao[MAX];
}Candidato;

//protótipo das funções
int menu();//Cria o menu de seleção de opções
int verifica_opcao(int opcao);//Verifica se a opção escolhida pelo usuário é válida
void cadastrar_candidato();//Faz o cadastro pelo nome do candidato
int verifica_data_nascimento(Candidato cadastro);//Verifica se a data de nascimento é valida
int verifica_sexo(Candidato cadastro);//Verifica se o sexo informado é válido
int valida_curso(Candidato cadastro);//Verifica se o curso está previamente cadastrado
int valida_estado(Candidato cadastro);//Verifica se o estado está previamente cadastrado
void cadastrar_curso();//Cadastrar curso
int recorrencia_curso(Candidato cadastro);//impede que um curso existente seja cadastrado novamente
void cadastrar_estado();//Cadastrar estado
int recorrencia_estado(Candidato cadastro);//impede que um estado existente seja cadastrado novamente
void listar_estado();//consultar pessoa por estado
void listar_nome();//consultar pessoa por nome
void listar_curso();//consultar pessoa por curso
void relatorio_demografico();//gerar relatório demográfico

Candidato cadastro;//declaração variável cadastro do tipo struct Candidato

// função principal
int main(void){
	
	system("color F0");//altera cor do terminal
	setlocale(LC_ALL,"Portuguese, Brazil");//localização de programas para o uso de caracteres especiais
	
	int opcao;
	
	//abre o menu de seleção de opções
	opcao = menu();
	system("cls");//limpar terminal
	
	//caso opção informada no menu seja inválida
	while((verifica_opcao(opcao))==0){
		system("cls");
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                      Opção inválida!                    |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		getchar();//voltar ao menu
		opcao = menu();
	}
	
	//faz a verificação de uma das opções validas escolhida pelo usuário
	switch((verifica_opcao(opcao))){
		case 1:
			cadastrar_candidato();break;
		case 2:
			cadastrar_curso();break;
		case 3:
			cadastrar_estado();break;
		case 4:
			listar_estado();break;
		case 5:
			listar_curso();break;
		case 6:
			listar_nome();break;
		case 7:
			relatorio_demografico();break;
		case 8:
			exit(0);
	}
}

//menu de seleção de opções

int menu(){
	int opcao;
	fflush(stdout);//buffer de saida
	system("cls");//limpar tela
	printf("===========================================================\n");
	printf("|                 **********MENU**********                |\n");
	printf("|                                                         |\n");
	printf("|                    Escolha uma opção                    |\n");
	printf("|                                                         |\n");
	printf("|1 - Cadastrar pessoa                                     |\n");
	printf("|2 - Cadastrar curso                                      |\n");
	printf("|3 - Cadastrar estado                                     |\n");
	printf("|4 - Listar pessoas por estado                            |\n");
	printf("|5 - Listar pessoas por curso desejado                    |\n");
	printf("|6 - Consultar pessoa por nome                            |\n");
	printf("|7 - Gerar relatório demográfico                          |\n");
	printf("|8 - Finalizar programa                                   |\n");
	printf("===========================================================\n");
	printf("\nopção: ");
	fflush(stdout);//buffer de saida
	scanf("%d", &opcao);
	getchar();//buffer
	
	return opcao;
}

//faz a verificação e retorna um valor para a opção escolhida

int verifica_opcao(int opcao){
	switch(opcao){
    case 1: return 1;//cadastrar pessoa
    case 2: return 2;//cadastrar curso
    case 3: return 3;//cadastar estado
    case 4: return 4;//listar pessoas por estado
    case 5: return 5;//listar pessoas por curso desejado
    case 6: return 6;//consultar pessoa por nome
    case 7: return 7;//gerar relatório demográfico
    case 8: return 8;//finalizar programa
    default: return 0;//opção inválida
	}
}

//Faz o cadastro de um novo candidato

void cadastrar_candidato(){	
	system("cls");//limpar terminal
	fflush(stdout);//buffer de saida
	FILE *relatorio_pessoa;//declaração da variável relatorio_pessoa do tipo FILE
	
	//Coleta de dados do candidato
	printf("===========================================================\n");
	printf("|              **********OBSERVAÇÃO**********             |\n");
	printf("|                                                         |\n");
	printf("|              Não use acentos e/ou pontução              |\n");
	printf("===========================================================\n");
	printf("\n");
	printf("===========================================================\n");
	printf("|       Informe o nome completo para ser cadastrado       |\n");
	printf("===========================================================\n");;
	printf("nome: ");
	fflush(stdout);//buffer de saida
	fgets(cadastro.nome, MAX, stdin);
	strupr(cadastro.nome);//converte para caracteres maiúsculos
	
	printf("===========================================================\n");	
	printf("|         Informe a data de nascimento(DD/MM/AAAA)        |\n");
	printf("===========================================================\n");
	printf("nascimento: ");
	fflush(stdout);//buffer de saida
	fgets(cadastro.data_nascimento, MIN, stdin);
		
	//verifica se data de nascimento é válida
	
    if((verifica_data_nascimento(cadastro))!=0){
        while((verifica_data_nascimento(cadastro))!=0){
        	printf("===========================================================\n");
        	printf("|                 **********ERRO**********                |\n");
        	printf("|                                                         |\n");
        	printf("|               data de nascimento inválida!              |\n");
        	printf("|    Informe uma data de nascimento válida(DD/MM/AAAA)    |\n");
        	printf("===========================================================\n");
        	printf("nascimento: ");
        	fflush(stdout);//buffer de saída
			fgets(cadastro.data_nascimento, MIN, stdin);
        }
    }
	
	printf("===========================================================\n");
	printf("|           Informe o sexo (masculino/feminino)           |\n");
	printf("===========================================================\n");
	printf("sexo: ");
	fflush(stdout);//buffer de saída
	fgets(cadastro.sexo, MIN, stdin);
	strupr(cadastro.sexo);
	
	//verifica se o sexo é válido
	if((verifica_sexo(cadastro))==1){
		while((verifica_sexo(cadastro))==1){
        	printf("===========================================================\n");
        	printf("|                 **********ERRO**********                |\n");
        	printf("|                                                         |\n");
        	printf("|                      sexo inválido!                     |\n");
        	printf("|       Informe um sexo válido (masculino/feminino)       |\n");
        	printf("===========================================================\n");
			printf("sexo: ");
			fflush(stdout);//buffer de saída
			fgets(cadastro.sexo, MIN, stdin);
			strupr(cadastro.sexo);		
		}
	}

	printf("===========================================================\n");
	printf("|                     Informe o curso                     |\n");
	printf("===========================================================\n");
	printf("curso: ");
	fflush(stdout);//buffer de saída
	fgets(cadastro.curso, MAX, stdin);
	strupr(cadastro.curso);
	
	//verifica se o curso informado já está previamente cadastrado
	if((valida_curso(cadastro))==0){
		system("cls");//limpar o terminal
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                  Curso não cadastrado..                 |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
	
	printf("===========================================================\n");
	printf("|          Informe a Unidade de Federação (UF)            |\n");
	printf("===========================================================\n");
	printf("UF: ");
	fflush(stdout);//buffer de saída
	fgets(cadastro.unidade_federacao, MIN, stdin);
	strupr(cadastro.unidade_federacao);
	
    //verifica se o estado informado já está previamente cadastrado
	if((valida_estado(cadastro))==0){
		system("cls");//limpar o terminal
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                 Estado não cadastrado..                 |\n");
		printf("|             pressione <enter> para continuar            |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
	
	relatorio_pessoa = fopen("relatorio_pessoa.txt", "a");//abre arquivo tipo texto para inclusão de dados
	
	//caso o arquivo não exista o programa retorna NULL e volta para o menu 
	if(relatorio_pessoa==NULL){
		printf("===========================================================\n");
		printf("|                Erro ao abrir o arquivo..                |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
	
	//caso todos dados informados sejam válidos armazena-os no arquivo relatorio_pessoa.txt
	fflush(stdin);
	fprintf(relatorio_pessoa, "%s", cadastro.nome);
	fprintf(relatorio_pessoa, "%s", cadastro.data_nascimento);
	fprintf(relatorio_pessoa, "%s", cadastro.sexo);
	fprintf(relatorio_pessoa, "%s", cadastro.curso);
	fprintf(relatorio_pessoa, "%s", cadastro.unidade_federacao);
		
	fclose(relatorio_pessoa);//fecha arquivo relatorio_pessoa.txt
	
	system("cls");
	printf("===========================================================\n");
	printf("|               Dados gravados com suceso...              |\n");
	printf("|           pressione <enter> para voltar ao MENU         |\n");
	printf("===========================================================\n");
	fflush(stdout);//buffer de saída
	getchar();//voltar ao menu
	main();
}

//valida a data de nascimento para o cadastro de um novo candidato

int verifica_data_nascimento(Candidato cadastro){
	int quantidade_digitos, cont, flag=0;
	int dia, mes, ano, tamanho_data;
	char *data_dia, *data_mes, *data_ano;
    
    tamanho_data = strlen(cadastro.data_nascimento);
    
    //verifica o tamnho da data de nascimento informada pelo usuário
    if(tamanho_data!=11){
    	flag++;
	}
    
    data_dia = strtok(cadastro.data_nascimento, "/");//separa a data de nascimento para pegar o dia
    dia = atoi(data_dia);//converte a string para inteiro
    
    //verifica se o dia é maior 31
    if(dia>31){
    	flag++;
	}
    
	data_mes = strtok(NULL, "/");//separa a data de nascimento para pegar o mês		
	mes = atoi(data_mes);//converte a string para inteiro
	
	//verifica se mês é maior que 12
	if(mes>12){
		flag++;
	}
  	return flag;
}

//valida o sexo para o cadastro de um novo candidato

int verifica_sexo(Candidato cadastro){
	char masculino[MIN]="MASCULINO\n";
	char feminino[MIN]="FEMININO\n";
	int flag=0, compara_feminino, compara_masculino;
	
	//compara a string informada com as strings validas
	if((strcmp(masculino, cadastro.sexo))!= 0 && (strcmp(feminino, cadastro.sexo))!=0){
		flag++;
	}
	
	return flag;
}

//Verifica se o curso já está cadastrado para incluir uma nova pessoa

int valida_curso(Candidato cadastro){
	FILE *relatorio_curso;
	char procura_curso[MAX];
	int flag=0;
	
	relatorio_curso = fopen("relatorio_curso.txt", "r");//abre o arquivo relatorio_curso.txt tipo texto para çeitura

	//verifica se não houve erro para abrir o arquivo	
	if(valida_curso == NULL){
		system("cls");//limpar o terminal
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                  Curso não cadastrado..                 |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
	
	//percorre todo o arquivo relatório_curso.txt para ver o curso informado existe
	while(fgets(procura_curso, MAX, relatorio_curso)!=NULL){
		if(strcmp(procura_curso, cadastro.curso)==0){
			flag++;
		}
	}
	
	fclose(relatorio_curso);
	
	return flag;
}

//Verifica se o estado já está cadastrado para incluir uma nova pessoa

int valida_estado(Candidato cadastro){
	FILE *relatorio_estado;
	char procura_uf[MIN];
	int flag=0;
	
	relatorio_estado = fopen("relatorio_estado.txt", "r");//abre o arquivo relatorio_estado.txt tipo texto para çeitura
	
	//verifica se não houve erro para abrir o arquivo
	if(valida_estado == NULL){
		system("cls");//limpar o terminal
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                 Estado não cadastrado..                 |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
	
	//percorre todo o arquivo relatório_estado.txt para ver o esatdo informado existe
	while((fgets(procura_uf, MIN, relatorio_estado))!=NULL){
		if(strcmp(procura_uf, cadastro.unidade_federacao)==0){
			flag++;
		}
	}	
	fclose(relatorio_estado);
	
	return flag;
}

//faz o cadastro de um novo curso

void cadastrar_curso(){
	system("cls");//limpar terminal
	fflush(stdin);//buffer de entrada
	FILE *relatorio_curso;
	
	relatorio_curso = fopen("relatorio_curso.txt", "a");//abre o arquivo relatorio_curso,txt para adicionar dados no final
	
	if(relatorio_curso==NULL){
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                Erro ao abrir o arquivo..                |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//buffer de entrada
		main();
	}
	printf("===========================================================\n");
	printf("|              **********OBSERVAÇÃO**********             |\n");
	printf("|                                                         |\n");
	printf("|              Não use acentos e/ou pontução              |\n");
	printf("===========================================================\n");
	printf("\n");
	printf("===========================================================\n");
	printf("|           Informe o curso para ser cadastrado           |\n");
	printf("===========================================================\n");
	printf("curso: ");
	fflush(stdout);//buffer de saída
	fgets(cadastro.curso, MAX, stdin);
	strupr(cadastro.curso);
	
	//verifica se o curso já está cadastrado
	if(recorrencia_curso(cadastro)!=0){
		system("cls");//limpar terminal
		printf("===========================================================\n");
		printf("|                **********ATENÇÃO*********               |\n");
		printf("|                                                         |\n");
		printf("|                 Curso já está cadastrado                |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//limpar terminal
		main();			
	}
	else{
		fprintf(relatorio_curso,"%s", cadastro.curso);
		fclose(relatorio_curso);
		fflush(stdin);//buffer de entrada
		system("cls");//limpar terminal
		printf("===========================================================\n");
		printf("|               Dados gravados com suceso..               |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();	
	}
}

//impede a duplicidade no cadastro de um curso

int recorrencia_curso(Candidato cadastro){
	char procura_curso[MAX];
	int flag=0;
	
	FILE *relatorio_curso;
	
	relatorio_curso = fopen("relatorio_curso.txt", "r");
	
	if(relatorio_curso==NULL){
		printf("===========================================================\n");
		printf("|                Erro ao abrir o arquivo..                |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();		
	}
	//compara todas as strings do arquivo relatorio_curso.txt com a informada
	while(fgets(procura_curso, MAX, relatorio_curso)!=NULL){
		if(strcmp(procura_curso, cadastro.curso)==0){
			flag++;//incrementa a variável flag caso exista uma de mesmo nome
		}
	}
	fclose(relatorio_curso);
	
	return flag;
 }

//faz o cadastro de um novo estado

void cadastrar_estado(){
	system("cls");//limpar terminal
	fflush(stdin);//buffer de entrada
	FILE *relatorio_estado;
	
	relatorio_estado = fopen("relatorio_estado.txt", "a");//abre o arquivo relatorio_curso,txt para adicionar dados no final
	
	if(relatorio_estado==NULL){
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                Erro ao abrir o arquivo..                |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
	printf("===========================================================\n");
	printf("|              **********OBSERVAÇÃO**********             |\n");
	printf("|                                                         |\n");
	printf("|              Não use acentos e/ou pontução              |\n");
	printf("===========================================================\n");
	printf("\n");
	printf("===========================================================\n");
	printf("|           Informe o estado para ser cadastrado          |\n");
	printf("===========================================================\n");
	printf("estado (ex. sao paulo): ");
	fflush(stdout);//buffer de saída
	fgets(cadastro.estado, MAX, stdin);
	strupr(cadastro.estado);
	
	printf("===========================================================\n");
	printf("|          Informe a Unidadde de Federação (UF)           |\n");
	printf("===========================================================\n");
	printf("UF (ex. sp): ");
	fflush(stdout);//buffer de saída
	fgets(cadastro.unidade_federacao, MAX, stdin);
	strupr(cadastro.unidade_federacao);
	
	//verifica se o estado já está cadastrado
	if(recorrencia_estado(cadastro)!=0){
		system("cls");
		printf("===========================================================\n");
		printf("|                **********ATENÇÃO*********               |\n");
		printf("|                                                         |\n");
		printf("|                 Estado já está cadastrado               |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();			
	}
	else{
		fprintf(relatorio_estado, "%s", cadastro.estado);
		fprintf(relatorio_estado, "%s", cadastro.unidade_federacao);
		fflush(stdin);
		fclose(relatorio_estado);
		system("cls");
		printf("===========================================================\n");
		printf("|               Dados gravados com suceso..               |\n");
		printf("|           pressione <enter> para voltar ao menu         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
}

//impede a duplicidade no cadastro de um estado

int recorrencia_estado(Candidato cadastro){
	char procura_estado[MAX];
	int flag=0;
	
	FILE *relatorio_estado;
	
	relatorio_estado = fopen("relatorio_estado.txt", "r");
	
	if(relatorio_estado==NULL){
		printf("===========================================================\n");
		printf("|                **********ATENÇÃO**********              |\n");
		printf("|                                                         |\n");
		printf("|                Erro ao abrir o arquivo..                |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();		
	}
	
	//compara todas as strings do arquivo relatorio_curso.txt com a informada
	while(fgets(procura_estado, MAX, relatorio_estado)){
		if(strcmp(procura_estado, cadastro.unidade_federacao)==0){
			flag++;//inclrementa a variável flag caso exista uma de mesmo nome
		}
	}
	fclose(relatorio_estado);
	
	return flag;
}

//lista os candidados por nome
 
void listar_nome(){
	system("cls");//limpar terminal
	fflush(stdin);//buffer de entrada
	
	char nome[MAX], procura_nome[MAX][MAX];
	int tamanho_nome, achou=0, linha_arquivo=0, flag=0;
	
	FILE *relatorio_pessoa;
	
	printf("===========================================================\n");
	printf("|            Informe o nome para ser consultado           |\n");
	printf("===========================================================\n");
	printf("Nome: ");
	gets(nome);
	system("cls");//limpar terminal

	//converte letras minúsculas para maiúsculas	
	for(tamanho_nome=0; tamanho_nome<strlen(nome); tamanho_nome++){
		nome[tamanho_nome] = toupper(nome[tamanho_nome]);	
	}
	
	relatorio_pessoa = fopen ("relatorio_pessoa.txt","r");
	
	if(relatorio_pessoa==NULL){
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                   pessoa não cadastrada                 |\n");
		printf("|           pressione <enter> para voltar ao menu         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
	
	//laço que ler todos os dados arquivo
	else{
		while(!feof(relatorio_pessoa)){
			achou=0;
			
			//ler todos os dados de cada candidato
			fgets(procura_nome[linha_arquivo], MAX, relatorio_pessoa);
			fgets(procura_nome[linha_arquivo+1], MAX, relatorio_pessoa);
			fgets(procura_nome[linha_arquivo+2], MAX, relatorio_pessoa);
			fgets(procura_nome[linha_arquivo+3], MAX, relatorio_pessoa);
			fgets(procura_nome[linha_arquivo+4], MAX, relatorio_pessoa);
			
			//verifica se o nome buscado está contido em qualquer string do arquivo
			if(strstr(procura_nome[linha_arquivo], nome)){
				achou=1;
			}
			
			//caso exista essa string imprime os dados relacionados
			if(achou==1){
				flag=1;
				printf("===========================================================\n");
				printf("                **********CADASTRO**********               \n");
				printf("\n");
				printf("Nome pesquisado: %s\n", nome);
				printf("\n");
				printf("Nome: %s", procura_nome[linha_arquivo]);
				printf("Nascimento: %s", procura_nome[linha_arquivo+1]);
				printf("Sexo: %s", procura_nome[linha_arquivo+2]);
				printf("Curso: %s", procura_nome[linha_arquivo+3]);
				printf("Estado: %s", procura_nome[linha_arquivo+4]);
				printf("===========================================================\n");
				achou=0;
				linha_arquivo = linha_arquivo + 6;
			}
		}
	}
	fflush(stdin);//buffer de entrada
	fclose(relatorio_pessoa);
	
	//caso não exista candidados cadastrados com o nome buscado
	if(flag==0){
		flag=0;
		system("cls");
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|                   pessoa não cadastrada                 |\n");
		printf("|           pressione <enter> para voltar ao menu         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();		
	}
	else{
		fclose(relatorio_pessoa);
		printf("===========================================================\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
}

//lista os candidados por estado

void listar_estado(){
	system("cls");//limpar terminal
	fflush(stdin);//buffer de entrada
	
	char estado[MAX], procura_estado[MAX][MAX];
	int achou=0, linha_arquivo=0, tamanho_nome, flag=0;
	
	FILE *relatorio_pessoa;
	
	printf("===========================================================\n");
	printf("|           Informe o estado para ser consultado          |\n");
	printf("===========================================================\n");
	printf("Unidade de Federação: ");
	fflush(stdout);//buffer de saída
	gets(estado);
	system("cls");//limpar terminal
	
	//converte letras minúsculas para maiúsculas
	for(tamanho_nome=0; tamanho_nome<strlen(estado); tamanho_nome++){
		estado[tamanho_nome] = toupper(estado[tamanho_nome]);
	}
	
	relatorio_pessoa = fopen("relatorio_pessoa.txt", "r");
	
	if(relatorio_pessoa == NULL){
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|  Não existe(m) candidato(s) cadastrado(s) nesse estado  |\n");
		printf("|           pressione <enter> para voltar ao menu         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();	
	}
	
	//laço que ler todos os dados do arquivo
	else{
		while(!feof(relatorio_pessoa)){
			
			//ler todos os dados de cada candidato
			achou=0;
			fgets(procura_estado[linha_arquivo], MAX, relatorio_pessoa);
			fgets(procura_estado[linha_arquivo+1], MAX, relatorio_pessoa);
			fgets(procura_estado[linha_arquivo+2], MAX, relatorio_pessoa);
			fgets(procura_estado[linha_arquivo+3], MAX, relatorio_pessoa);
			fgets(procura_estado[linha_arquivo+4], MAX, relatorio_pessoa);
			
			//verifica se o nome buscado está contido em qualquer string do arquivo
			if(strstr(procura_estado[linha_arquivo+4], estado)){
				achou=1;
			}
			if(achou==1){
				
				//caso essa string exista imprime todos os dados relacionados
				flag=1;
				printf("===========================================================\n");
				printf("                **********CADASTRO**********               \n");
				printf("\n");
				printf("Estado pesquisado: %s\n", estado);
				printf("\n");
				printf("Nome: %s", procura_estado[linha_arquivo]);
				printf("Nascimento: %s", procura_estado[linha_arquivo+1]);
				printf("Sexo: %s", procura_estado[linha_arquivo+2]);
				printf("Curso: %s", procura_estado[linha_arquivo+3]);
				printf("Estado: %s", procura_estado[linha_arquivo+4]);
				printf("===========================================================\n");
				achou=0;
				linha_arquivo+=6;
			}
		}
	}
	if(flag==0){
		system("cls");
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|  Não existe(m) candidato(s) cadastrado(s) nesse estado  |\n");
		printf("|           pressione <enter> para voltar ao menu         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();		
	}
	else{
		fclose(relatorio_pessoa);
		printf("===========================================================\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
}

//lista os candidados por estado

void listar_curso(){
	system("cls");//limpar terminal
	fflush(stdin);//buffer de entada
	
	char curso[MAX], procura_curso[MAX][MAX];
	int achou=0, linha_arquivo=0, tamanho_nome, flag=0;
	
	FILE *relatorio_pessoa;
	
	fflush(stdin);
	printf("===========================================================\n");
	printf("|            Informe o curso para ser consultado          |\n");
	printf("===========================================================\n");
	printf("Curso: ");
	gets(curso);
	system("cls");//limpar terminal
	
	//converte letras minúsculas para maiúsculas
	for(tamanho_nome=0; tamanho_nome<strlen(curso); tamanho_nome++){
		curso[tamanho_nome] = toupper(curso[tamanho_nome]);
	}
	
	relatorio_pessoa = fopen("relatorio_pessoa.txt", "r");
	
	if(relatorio_pessoa == NULL){
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|  Não existe(m) candidato(s) cadastrado(s) nesse curso   |\n");
		printf("|           pressione <enter> para voltar ao menu         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();	
	}
	
	//laço que ler todos os dados do arquivo
	else{
		while(!feof(relatorio_pessoa)){
			
			//ler todos os dados de cada candidato
			achou=0;
			fgets(procura_curso[linha_arquivo], MAX, relatorio_pessoa);
			fgets(procura_curso[linha_arquivo+1], MAX, relatorio_pessoa);
			fgets(procura_curso[linha_arquivo+2], MAX, relatorio_pessoa);
			fgets(procura_curso[linha_arquivo+3], MAX, relatorio_pessoa);
			fgets(procura_curso[linha_arquivo+4], MAX, relatorio_pessoa);
			
			//verifica se o nome buscado está contido em qualquer string do arquivo
			if(strstr(procura_curso[linha_arquivo+3], curso)){
				achou=1;
			}
			if(achou==1){
				
				//caso essa string exista imprime todos os dados relacionados
				flag=1;
				printf("===========================================================\n");
				printf("                **********CADASTRO**********               \n");
				printf("\n");
				printf("Curso pesquisado: %s\n", curso);
				printf("\n");
				printf("Nome: %s", procura_curso[linha_arquivo]);
				printf("Nascimento: %s", procura_curso[linha_arquivo+1]);
				printf("Sexo: %s", procura_curso[linha_arquivo+2]);
				printf("Curso: %s", procura_curso[linha_arquivo+3]);
				printf("Estagdo: %s", procura_curso[linha_arquivo+4]);
				printf("===========================================================\n");
				achou=0;
				linha_arquivo+=6;
			}
		}
	}
	if(flag==0){
		system("cls");
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|   Não existe(m) candidato(s) cadastrado(s) nesse curso  |\n");
		printf("|           pressione <enter> para voltar ao menu         |\n");
    	printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();		
	}
	else{
		fclose(relatorio_pessoa);
		printf("===========================================================\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdin);//buffer de entrada
		getchar();//voltar ao menu
		main();
	}	
}

//gerar o relatório demográfico com os percentuais

void relatorio_demografico(){
	char masculino[MIN]="MASCULINO\n";
	char feminino[MIN]="FEMININO\n";
	char procura_pessoa[MAX][MAX];
	int quantidade_homem=0, quantidade_mulher=0, linha_arquivo=0, quantidade_cadastro=0;
	int  achou_homem=0,  achou_mulher=0;
	char nascimento[MAX], *data;
	int tam, ano, idade, tamanho_data;
	int quinze_vinte=0, vinteUm_vinteCinco=0, vinteSeis_trinta=0, acimaTrinta=0;  
	double percentual_homem, percentual_mulher;
	double percentual_primeira, percentual_segunda, percentual_terceira, percentual_quarta;
	
	system("cls");//limpar terminal
	FILE *relatorio_pessoa;
	fflush(stdin);//buffer de entrada
	
	relatorio_pessoa = fopen("relatorio_pessoa.txt", "r+");
	
	if(relatorio_pessoa==NULL){
		printf("===========================================================\n");
		printf("|               **********ATENÇÃO**********               |\n");
		printf("|                                                         |\n");
		printf("|             Não há candidato(s) cadastrado(s)           |\n");
		printf("|           pressione <enter> para voltar ao MENU         |\n");
		printf("===========================================================\n");
		fflush(stdout);//buffer de saída
		getchar();//voltar ao menu
		main();
	}
	
	while(fgets(procura_pessoa[linha_arquivo], MAX, relatorio_pessoa)!=NULL){

		//ler todos os dados de cada candidato
		fgets(procura_pessoa[linha_arquivo+1], MAX, relatorio_pessoa);
		fgets(procura_pessoa[linha_arquivo+2], MAX, relatorio_pessoa);
		fgets(procura_pessoa[linha_arquivo+3], MAX, relatorio_pessoa);
		fgets(procura_pessoa[linha_arquivo+4], MAX, relatorio_pessoa);
		
		//calcula idade
		tamanho_data = strlen(procura_pessoa[linha_arquivo+1]);		
		if(procura_pessoa[linha_arquivo+1][tamanho_data-1]=='\n')procura_pessoa[linha_arquivo+1][--tamanho_data]=0;//retira o end of line do fgets
		
		data = strtok(procura_pessoa[linha_arquivo+1], "/");//separa a primeira parte da string de data de nascimento (dia)
		data = strtok(NULL, "/");//separa a segunda parte da string de data de nascimento (mes)
		data = strtok(NULL, "/");//separa a primeira parte da string de data de nascimento (ano)
		
		ano = atoi(data);//converte string data que correspende ao ano de nascimento para inteiro
		
		idade = 2019 - ano;//calcula idade de cada candidato
		
		if(idade>=15 && idade<=20){
			quinze_vinte++;
		}
		else if(idade>=21 && idade<=25){
			vinteUm_vinteCinco++;
		}
		else if(idade>=26 && idade<=30){
			vinteSeis_trinta++;
		}
		else if(idade>30){
			acimaTrinta++;
		}
		
		//verifica a quantidade de homens, mulheres e cadastros
		if(strstr(procura_pessoa[linha_arquivo+2], masculino)){
			achou_homem=1;
		}
		else if(strstr(procura_pessoa[linha_arquivo+2], feminino)){
			achou_mulher=1;
		}
		if(achou_homem==1){
			quantidade_homem++;
			quantidade_cadastro++;
			linha_arquivo+=6;
		}
		else if(achou_mulher==1){
			quantidade_mulher++;
			quantidade_cadastro++;
			linha_arquivo+=6;
		}
		achou_homem=0;
		achou_mulher=0;
	}

	//calcula o perentual de faixas etárias
	percentual_primeira = (quinze_vinte*100)/quantidade_cadastro;
	percentual_segunda = (vinteUm_vinteCinco*100)/quantidade_cadastro;
	percentual_terceira = (vinteSeis_trinta*100)/quantidade_cadastro;
	percentual_quarta = (acimaTrinta*100)/quantidade_cadastro;
	
	//calcula percentual de homens e mulheres
	percentual_homem = (quantidade_homem*100)/quantidade_cadastro;
	percentual_mulher = (quantidade_mulher*100)/quantidade_cadastro;
	
	printf("===========================================================\n");
	printf("                **********RELATÓRIO**********              \n");
	printf("\n");
	printf("Quantidade de cadastros: %d\n", quantidade_cadastro);
	printf("\n");
	printf("Percentual homens: %.2lf%%\n", percentual_homem);
	printf("Percentual mulheres: %.2lf%%\n", percentual_mulher);
	printf("-----------------------------------------------------------\n");
	printf("Percentual entre 15 e 20 anos: %.2lf%%\n", percentual_primeira);
	printf("Percentual entre 21 e 25 anos: %.2lf%%\n", percentual_segunda);
	printf("Percentual entre 26 e 30 anos: %.2lf%%\n", percentual_terceira);
	printf("Percentual acima de 30 anos: %.2lf%%\n", percentual_quarta);
	printf("===========================================================\n");
	
	fclose(relatorio_pessoa);
	printf("===========================================================\n");
	printf("|           pressione <enter> para voltar ao MENU         |\n");
	printf("===========================================================\n");
	fflush(stdout);//buffer de saída
	getchar();//voltar ao menu
	main();
}
