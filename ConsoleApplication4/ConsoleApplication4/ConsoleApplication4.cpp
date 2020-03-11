// ConsoleApplication4.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include <mutex>
#include <thread>
#include <vector>
#include <atomic>

std::atomic<int> total = 0;
std::mutex m;

int m3[4][4] = {{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
				};

void calc(std::vector<int> tab, std::string parite) {
	int somme = 0;
	for (int number : tab) {
		if (parite == "pair")
		{
			if (number % 2 == 0)
			{
				m.lock();
				std::cout << number << " est un nombre pair." << std::endl;
				m.unlock();
			}
		}
		else if (parite == "impair")
		{
			if (number % 2 == 1)
			{
				m.lock();
				std::cout << number << " est un nombre impair." << std::endl;
				m.unlock();
			}

		}
	}
}

void pair(std::vector<int> tab) {
	int somme = 0;
	for (int number : tab) {
		if (number % 2 == 0)
		{
			m.lock();
			std::cout << number << std::endl;
			m.unlock();
		}
	}
}
void impair(std::vector<int> tab) {
	int somme = 0;
	for (int number : tab) {
		if (number % 2 == 1)
		{
			m.lock();
			std::cout << number << std::endl;
			m.unlock();
		}
	}
}

void dec()
{
	for (int i = 0; i < 100000; i++)
	{
		total--;
	}
}

void inc()
{
	for (int i = 0; i < 100000; i++)
	{
		total++;
	}
}

void produitMatrice(int m1[4][4], int m2[4][4]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m3[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}

		}
	}
}
void produitMatriceTh(int m1[4][4], int m2[4][4],int i) {
		for (int j = 0; j < 4; j++)
		{
			m3[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}

		}
}

void displayMatrice() {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << m3[i][j] << " ";
			

		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}
		


	int main() {
		/*std::vector<int> tab1{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

		//std::thread t1(pair, tab1);
		//std::thread t2(impair, tab1);
		std::thread t1(inc);
		std::thread t2(dec);
		t1.join();
		t2.join();
		std::cout << "Le total est " << total << std::endl;
		*/

		int m1[4][4] = {{1,2,3,4},
						{1,2,3,4},
						{1,2,3,4},
						{1,2,3,4}
		};

		int m2[4][4] = {{1,2,3,4},
						{1,2,3,4},
						{1,2,3,4},
						{1,2,3,4}
						};

		

		produitMatrice(m1, m2);
		displayMatrice();
		std::thread t1(produitMatriceTh, m1, m2, 0);
		std::thread t2(produitMatriceTh, m1, m2, 1);
		std::thread t3(produitMatriceTh, m1, m2, 2);
		std::thread t4(produitMatriceTh, m1, m2, 3);
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		displayMatrice();
}

	
	


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
