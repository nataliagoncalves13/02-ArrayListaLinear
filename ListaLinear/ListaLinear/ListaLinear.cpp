// Natalia dos Santos Gonçalves
#include <iostream>
using namespace std;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
int posicaoElemento(int valor);
//--------------------------


const int MAX = 10;;
int lista[MAX]{};
int nElementos = 0;


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Linear";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	nElementos = 0;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (nElementos == 0)
	{
		cout << " A lista esta vazia \n";
	}
	else {
		cout << "Elementos: \n";
		for (int n = 0; n < nElementos; n++) {
			cout << lista[n] << endl;
		}
	}
}

void inserirElemento()
{
	int pos;
	int valor;
	if (nElementos < MAX) {
		cout << "Digite o elemento: ";
		cin >> valor;
		pos = posicaoElemento(valor);

		if (pos != -1)
		{
			cout << "Elemento já esta na lista" << endl;
		}
		else
		{
			lista[nElementos] = valor;
			nElementos++;
		}

	}
	else {
		cout << "Lista cheia";
	}

}

void excluirElemento()
{
	int eElemento = 0;
	
	cout << "Digite o elemento que deseja excluir: ";
	cin >> eElemento;
	int pos = posicaoElemento(eElemento);


	if (pos != -1) {
		for (int i = pos; i < nElementos - 1; i++) {
			lista[i] = lista[i + 1];
			cout << "O elemento foi excluido com sucesso." << endl;
		}
		nElementos--;
	}
	else
	{
		cout << "O elemento nao foi encontrado." << endl;
	}
}


void buscarElemento()
{
	int valor;
	cout << "Digite o elemento que queira buscar: ";
	cin >> valor;
	int pos = posicaoElemento(valor);

	if (pos != -1) {
		cout << "O elemento foi encontrado na posicao" << pos << endl;
	}
	else
	{
		cout << "O elemento digitado nao foi encontrado" << endl;
	}
}

int posicaoElemento(int busca)
{
	int posicao = -1;
	for (int i = 0; i < nElementos; i++) {
		if (busca == lista[i]) {
			posicao = i;
		}
	}
	return posicao;
}
