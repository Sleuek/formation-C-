#pragma once

#include <iostream>


class maillon
{

	friend class listeChainee;

private:
	int data;
	maillon * next;
	template <typename T>

	maillon(T d);
	maillon();

};


class listeChainee
{
public:
	template <typename T>
	void add(T d);
	void display();
	listeChainee();

private:
	
	maillon * tete;
};

