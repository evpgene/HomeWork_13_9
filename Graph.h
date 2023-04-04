#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000 // очень большое число
#include "Person.h"
#include <vector>

class Graph
{
public:
	Graph();
	~Graph();
	
	void addVertex(const Person& person);// добавление вершины
	void addEdge(const Person& person1, const Person& person2);// добавление ребра
	void delVertex(const Person& person);// удаление вершины
	void delEdge(const Person& person1, const Person& person2);// удаление ребра

	void findMinDistancesFloyd(); //поиск минимального пути алгоритм Флойда-Уоршелла

	int getCount() const;
	void printVertexes();
	Person getVertex(int id) const;
	bool edgeExists(const Person& person1, const Person& person2) const;
	bool vertexExists(const Person& person) const;

private:
	Person vertexes[SIZE]; // хранилище вершин
	int matrix[SIZE][SIZE]; // матрица смежности
	int vertexCount; // количество добавленных вершин
};

