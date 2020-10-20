#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int soma_total_em_vetor(std::vector<int> &vec)
{
	int soma_total = 0;

	if (vec.empty())
	{
		return 0;
	}

	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		soma_total += *it;
	}

	return soma_total;
}

int maximo_dois_inteiros(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
/*
int solucao_programacao_nao_dinamica(std::vector<int> &vec, int quantidade_diamantes, int soma_desejada)
{

	if (quantidade_diamantes == 0 || soma_desejada == 0)
	{
		return 0;
	}

	if (vec.at(quantidade_diamantes - 1) > soma_desejada)
	{
		return solucao_programacao_nao_dinamica(vec, quantidade_diamantes - 1, soma_desejada);
	}
	else 
	{
		int aux = vec.at(quantidade_diamantes - 1) + solucao_programacao_nao_dinamica(
			vec,
			quantidade_diamantes - 1,
			soma_desejada - vec.at(quantidade_diamantes - 1)
		);
		return maximo_dois_inteiros(aux, solucao_programacao_nao_dinamica(
			vec,
			quantidade_diamantes - 1,
			soma_desejada
		));
	}
}
*/
int solucao_programacao_dinamica(std::vector<int> &vec, int quantidade_diamantes)
{
	int soma_total_de_pesos = soma_total_em_vetor(vec);

	int tamanho_y = ((soma_total_de_pesos / 2) + 1);
	int tamanho_x = quantidade_diamantes + 1;

	int arr[tamanho_x][tamanho_y];

	for (int i = 0; i < tamanho_x; ++i)
	{
		for (int j = 0; j < tamanho_y; ++j)
		{
			arr[i][j] = 0;
		}
	}

	
	for (int i = 1; i < tamanho_x; ++i)
	{
		for (int j = 1; j < tamanho_y; ++j)
		{
			if (vec.at(i - 1) <= j)
			{
				int aux = vec.at(i-1) + arr[i-1][j-vec.at(i-1)];
				arr[i][j] = maximo_dois_inteiros(arr[i-1][j], aux);
			}
			else
			{
				arr[i][j] = arr[i-1][j];
			}
		}
	}

	int resultado = soma_total_de_pesos - (2 * arr[tamanho_x-1][tamanho_y-1]);


	return resultado;
}

void imprime_vetor(std::vector<int> &vec)
{
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	int quantidade_diamantes;
	std::vector<int> pesos_dos_diamantes_1;
	//std::vector<int> pesos_dos_diamantes_2;

	std::cin >> quantidade_diamantes;

	int peso_de_um_diamante;

	for (auto i = 0; i < quantidade_diamantes; ++i)
	{
		std::cin >> peso_de_um_diamante;
		pesos_dos_diamantes_1.push_back(peso_de_um_diamante);
		//pesos_dos_diamantes_2.push_back(peso_de_um_diamante);
	}

	// ----- ALGORITMO DINAMICO
	auto start_algorithm_1 = std::chrono::steady_clock::now();
	std::cout << solucao_programacao_dinamica(pesos_dos_diamantes_1, quantidade_diamantes) << std::endl;
	auto end_algorithm_1 = std::chrono::steady_clock::now();
	auto diff_1 = end_algorithm_1 - start_algorithm_1;
	std::cout << std::chrono::duration <double, std::milli>(diff_1).count() << std::endl;

/*
	// ----- ALGORITMO NAO DINAMICO
	int soma_total = soma_total_em_vetor(pesos_dos_diamantes_2);
	int soma_desejada = ((soma_total / 2));

	auto start_algorithm_2 = std::chrono::steady_clock::now();
	int resultado = soma_total - (2 * solucao_programacao_nao_dinamica(pesos_dos_diamantes_2, quantidade_diamantes, soma_desejada));
	std::cout << resultado << std::endl;
	auto end_algorithm_2 = std::chrono::steady_clock::now();
	auto diff_2 = end_algorithm_2 - start_algorithm_2;
	std::cout << std::chrono::duration <double, std::milli>(diff_2).count() << std::endl;
*/
	
	return 0;
}