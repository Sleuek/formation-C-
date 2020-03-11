
#include <string>
#include <iostream>
#include <string>

class animal
{
protected:
	std::string espece;
	std::string continent;

public:
	~animal();
	animal(std::string e, std::string c);

	void afficher();
};


class gadget
{
protected:
	int prix;

public:
	gadget(int p);
	~gadget();

	void afficher();
};

#pragma once
class enDanger
{
protected:
	int nombre;

public:
	enDanger(int n);
	~enDanger();

	void afficher();
};


class peluche : enDanger, gadget, animal 
{
public:
	peluche(std::string espece, std::string continent, int nombre, int prix);
	void etiquette();
};
