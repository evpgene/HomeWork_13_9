#pragma once
#include <iostream>
struct Person
{
	Person() = default;
	explicit Person(const std::string& name) :_name(name) { };

	int _id{ -1 }; //ИД 
	std::string _name{""};//имя
};

