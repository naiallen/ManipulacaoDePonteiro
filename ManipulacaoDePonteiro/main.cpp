/*---------------------------------------------------------------------------*/
/* 				Exemplo de Manipulacao de Ponteiros 				         */
/* - Uma variável declarada como ponteiro é capaz de armazenar um endereço de*/
/*memória ou o endereço de outra variável									 */				
/* - Operadores:															 */
/*		-> '&': operador utilizado para referenciar um variável ou seja, é	 */
/*				utilizado para saber o endereço da variável. É chamado de    */
/*				operador de referencia ou operador de endereço.				 */
/*		-> '*': operador de usado para acessar o conteúdo da variável, esse  */
/*              processo é chamado de derreferenciamento do ponteiro		 */
/*- Declaração: tipo *ptr													 */
/*------------------------------------------------------------------*/
/*	Autor: Naiallen Carvalho
/* 	Data:18/11/2018
/*------------------------------------------------------------------*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctime>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

//estrutura de enderecos de memoria 
struct horario
{
	int *pHora;
	int *pMinuto;
	int *pSegundo;
};



//Manipula Char================================================================
//função para duplicar a cadeia de caracter
char* duplica(char *str)
{
	int qtd = strlen(str);
	char *w_local = new char[(2 * qtd + 1)*(sizeof(char))]; //aloca espaço na memória
	strcpy(w_local, str); //copia a string para w_local
	strcat(w_local, str); //concatena as strings
	return w_local;
}
//============================================================================

//Manipula vetor
//função para duplicar a cadeia de caracter
int somaVetor(int *vetor, int s, int& resultado)
{
	for (int ii = 0; ii < s; ii++)
	{
		resultado += *vetor;
		vetor++;
	}
	return 0;
}


int main()
{
	// Referenciamento e De - referenciamento de uma variavel=====================
	
	int variavel = 3;
	int *ptr_variavel = &variavel; //Referenciamento -> passa o endereço da variavel para o ponteiro
	
	std::cout << " Valor da variavel              -> variavel:      " << variavel << std::endl
			  << " Referenciamento da variavel    -> &variavel:     " << &variavel << std::endl
			  << " Endereco da variavel           -> ptr_variavel:  " << ptr_variavel << std::endl
			  << " De-referenciamento do ponteiro -> *ptr_variavel: " << *ptr_variavel << std::endl;

	std::cout << std::endl;
	//============================================================================

	// Referenciamento e De - referenciamento de um vetor/array===================
	int vetor[3] = { 1, 2, 3 }; //declaração do vetor
	int *ptr_vetor = &vetor[0]; //aponta para o endereço de memoria do primeiro termo do vetor

	//printa os valores do vetor
	for (auto v : vetor)
		std::cout << v << " ";
	std::cout << std::endl;

	std::cout << "Primeiro termo do vetor: " << *ptr_vetor << " - Endereco: " << ptr_vetor << std::endl;
	//O tipo de dado int tem 4 bytes, e como os arrays são armazenados de forma contigua
	//na memoria, o endereço do segundo termo do vetor saltará 4 posições
	ptr_vetor++; // Acessando o segundo elemento do vetor
	std::cout << "Segundo termo do vetor:  " << *ptr_vetor << " - Endereco: " << ptr_vetor << std::endl;
	ptr_vetor++; // Acessando o terceiro elemento do vetor, ptr_vetor salta mais 4 posições 
	std::cout << "Terceiro termo do vetor: " << *ptr_vetor << " - Endereco: " << ptr_vetor << std::endl;

	std::cout << std::endl;
	//============================================================================

	// Referenciamento e De - referenciamento de uma Matriz=======================
	double matriz[2][3] = { { 8, 5, 3 }, { 1, 7, 6 } };
	double	*ptr_matriz = nullptr; //ponteiro nulo
	//printa a matriz
	for (int i = 0; i != 2; ++i) //linha
	{
		for (int j = 0; j != 3; ++j)	//coluna
			std::cout << matriz[i][j] << "\t";
		std::cout << std::endl;
	}

	ptr_matriz = &matriz[0][0]; //referencia o primeiro termo
	std::cout << "M[0,0]: " << *ptr_matriz << " - Addr: " << ptr_matriz << std::endl;
	ptr_matriz++;
	//como double tem 8 bytes, o próximo endereço pula 8 posições de memoria
	std::cout << "M[0,1]: " << *ptr_matriz << " - Addr: " << ptr_matriz << std::endl;

	std::cout << std::endl;
	//============================================================================
	
	
	

	// Referenciamento e De - referenciamento de uma Estrutura====================
	struct horario agora;	//agora é o nome da estrutura
	time_t now = time(NULL);
	struct tm *now_tm = std::localtime(&now);
	int hora = now_tm->tm_hour, min = now_tm->tm_min, seg = now_tm->tm_sec;

	//passando a referencia (&)
	agora.pHora = &hora;
	agora.pMinuto = &min;
	agora.pSegundo = &seg;
	//de-referenciar um ponteiro, isto é, acessar o valor armazenado no endereco de memoria (*)
	std::cout << "Horario - " << *agora.pHora << ":" << *agora.pMinuto << ":" << *agora.pSegundo << std::endl;
	
	//============================================================================


	//ALOCAÇÃO DE MEMORIA DINAMICA================================================
	//Variaveis alocadas estaticamente desaparecem qundo a execução termina
	//Variaveis alocadas dinamicamente continuam a existir mesmo depois que a execução
	//termina, por isso sempre que alocar memoria dinamicamente, é necessario deletar 
	//a variavel
	//Em c++ a alocacao é efetuada com o comando 'new' 
	int *a = new int[10]; //reserva 10 endereços de memorias com o tamanho int 
	a[0] = 1;
	a[1] = 3;
	delete[] a;

	//Exemplo de alocacao de memoria, ponteiro e funcao
	char word[50];
	char *w_final;
	std::cout << "Informe uma cadeia de caracteres: ";
	std::cin >> word;
	w_final = duplica(&word[0]); //passa a referência
	std::cout << w_final << std::endl;
	delete w_final; //se alocou espaço na memoria, tem que liberar

	std::cout << std::endl;
	//============================================================================

	//passando ponteiro de um vetor para uma funcao===============================
	int vetor_sum[5] = { 8, 5, 3, 7, 6 };
	int resultado = 0;
	somaVetor(&vetor_sum[0], 5, resultado);
	std::cout << "Resultado: " << resultado << std::endl;	
	//============================================================================

	system("pause");
	return 0;
}
