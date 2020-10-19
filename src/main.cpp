#include <iostream>
#include <vector>
#include <chrono>

bool checar_igualdade_de_inteiros(int a, int b)
{
	if (a == b) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

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

	/*
	Iteramos sobre cada peso de pedra "i" armazenado em vec e sobre cada peso "p" de 1 até soma_total/2,
	e tentamos achar o maior peso formados pelas pedras até "i" que chega proximo ou igual a "p".
	*/
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
	std::vector<int> pesos_dos_diamantes_2;

	std::cin >> quantidade_diamantes;

	int peso_de_um_diamante;

	for (auto i = 0; i < quantidade_diamantes; ++i)
	{
		std::cin >> peso_de_um_diamante;
		pesos_dos_diamantes_1.push_back(peso_de_um_diamante);
		pesos_dos_diamantes_2.push_back(peso_de_um_diamante);
	}

	auto start_algorithm_2 = std::chrono::steady_clock::now();
	std::cout << solucao_programacao_dinamica(pesos_dos_diamantes_2, quantidade_diamantes) << std::endl;
	auto end_algorithm_2 = std::chrono::steady_clock::now();
	auto diff_2 = end_algorithm_2 - start_algorithm_2;
	std::cout << std::chrono::duration <double, std::milli>(diff_2).count() << std::endl;

	return 0;
}