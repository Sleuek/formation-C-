// ConsoleApplication3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Fraction.h"
#include "listeChainee.h"






template <typename T>
maillon::maillon(T d)
{
	data = d, next = NULL;
}


maillon::maillon()
{
	data = NULL, next = NULL;
}

listeChainee::listeChainee()
{
}


template <typename T>
void listeChainee::add(T d)
{
	std::cout << "added" << std::endl;
	if (tete->data == NULL) {
		tete->data = d;
		tete->next = NULL;
	}
	else {
		maillon * present = new maillon();
		maillon * nouveau = new maillon(d);

		present = tete;
		while (present->next != NULL) {
			present = present->next;
		}
		present->next = nouveau;
		tete->next = nouveau;
	}

}


void listeChainee::display()
{
	maillon * present = new maillon();
	present = tete;
	while (present->next != NULL) {
		std::cout << present->data << std::endl;
		present = present->next;
	}
}



template <typename T>
void tri(T tab[10])
{
	T intermediaire;
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 10;j++) {
			if (tab[j] < tab[i]) {
				intermediaire = tab[i];
				tab[i] = tab[j];
				tab[j] = intermediaire;
			}
		}
	}
}

void execTri() {
	int tab[10] = { 1,3,2,6,5,8,10,7,9,10 };
	for (int i = 0; i < 10; i++)
	{
		std::cout << tab[i] << "|";
	}
	std::cout << "\n";
	tri<int>(tab);
	for (int i = 0; i < 10; i++)
	{
		std::cout << tab[i] << "|";
	}


}


int main()
{
	Fraction a(10, 5);     
	Fraction b(2);        
	Fraction c;       

	//std::cin >> b;

	c = a + b;
	std::cout << c << std::endl;
	c = a - b;
	std::cout << c << std::endl;
	c = a * b;
	std::cout << c << std::endl;
	c = a / b;
	std::cout << c << std::endl;

	

	listeChainee liste;
	liste.add<int>(3);
	liste.add<int>(2);
	liste.add<int>(4);
	liste.display();






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
