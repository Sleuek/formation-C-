#pragma once
#include <iostream>
#include <string>

class animal
{

public: 
	virtual std::string getName() = 0;
	virtual void setName(std::string name) = 0;
	virtual void noise() = 0;
};

class chat : public animal
{
private:
	std::string m_name;
public:
	chat(std::string name);

	std::string getName();
	void setName(std::string name);
	void noise();
};

class chien : public animal
{
private:
	std::string m_name;
public:
	chien(std::string name);

	std::string getName();
	void setName(std::string name);
	void noise();
};

class rat : public animal
{
private:
	std::string m_name;
public:
	rat(std::string name);

	std::string getName();
	void setName(std::string name);
	void noise();
};

class animalFactory
{
public:
	animalFactory();

	animal * createAnimal(std::string espece, std::string name);
};

class singFactory : public animalFactory
{
public:
	singFactory();
	animalFactory * m_af;
private:
	animalFactory * getFactory();
};