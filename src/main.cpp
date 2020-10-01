#include <iostream>
#include <vector>

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

	return 0;
}