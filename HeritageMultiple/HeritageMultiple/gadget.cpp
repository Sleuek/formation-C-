#include "gadget.h"
#include <iostream>

gadget::gadget(int p)
{
	prix = p;
}

gadget::~gadget() 
{
}

void gadget::afficher()
{
	std::cout << "Prix du gadget : " << prix << std::endl;
}

enDanger::enDanger(int n)
{
	nombre = n;
}

enDanger::~enDanger()
{
}

void enDanger::afficher()
{
	std::cout << "Nombre d animaux en danger : " << nombre << std::endl;
}

animal::animal(std::string e, std::string c) {
	espece = e;
	continent = c;
}

animal::~animal()
{
}

void animal::afficher()
{
	std::cout << "[" << continent << "] - Espece : " << espece << std::endl;
}

peluche::peluche(std::string espece, std::string continent, int nombre, int prix) {
	espece = espece;
}