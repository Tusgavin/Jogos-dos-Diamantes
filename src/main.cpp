#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

#define MAX(a, b) ((a) > (b) ? (1) : (0))

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

std::pair<int, int> checar_menor_elemento_em_vector(std::vector<int> &vec)
{
	std::vector<int>::size_type unitario = 1;

	if (!vec.empty())
	{
		int menor_peso = vec.at(0);
		int indice_menor_peso = 0;

		if (vec.size() == unitario)
		{
			return std::make_pair(vec.at(0), 0);
		}

		for (std::vector<int>::size_type i = 1; i < vec.size(); ++i)
		{
			if (menor_peso > vec.at(i))
			{
				indice_menor_peso = i;
				menor_peso = vec.at(i);
			}
		}

		auto par_peso_indice = std::make_pair(menor_peso, indice_menor_peso);

		return par_peso_indice;
	}
	else 
	{
		return std::make_pair(-1, -1);
	}
}

int solucao_programacao_dinamica(std::vector<int> &vec)
{
	return 0;
}

void imprime_vetor(std::vector<int> &vec)
{
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

int solucao_divisao_e_conquista(std::vector<int> &vec)
{

	std::vector<int> vetor_auxiliar;
	std::vector<int>::size_type unitario = 1;

	while (true)
	{
		for (std::vector<int>::size_type j = 1; j < vec.size(); ++j)
		{
			if (checar_igualdade_de_inteiros(vec.at(0), vec.at(j)))
			{
				vetor_auxiliar.push_back(0);
			}
			else
			{
				int novo_peso = vec.at(0) - vec.at(j);
				vetor_auxiliar.push_back(std::abs(novo_peso));
			}
		}

		auto menor_peso_indice_atual = checar_menor_elemento_em_vector(vetor_auxiliar);

		std::vector<int>::iterator it_1 = vec.begin();
		std::vector<int>::iterator it_2 = vec.begin() + std::get<1>(menor_peso_indice_atual);

		vec.erase(it_1);
		vec.erase(it_2);

		vec.push_back(std::get<0>(menor_peso_indice_atual));

		if (vec.size() == unitario)
		{
			break;
		}

		vetor_auxiliar.clear();

	}

	int peso_final = vetor_auxiliar.at(0);

	return peso_final;
}

int main(int argc, char *argv[])
{
	int quantidade_diamantes;
	std::vector<int> pesos_dos_diamantes;

	std::cin >> quantidade_diamantes;

	int peso_de_um_diamante;

	for (auto i = 0; i < quantidade_diamantes; ++i)
	{
		std::cin >> peso_de_um_diamante;
		pesos_dos_diamantes.push_back(peso_de_um_diamante);
	}

	std::cout << "Peso final: " << solucao_divisao_e_conquista(pesos_dos_diamantes) << std::endl;


	return 0;
}