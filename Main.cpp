#include <iostream>
#include "Graph.h"


int main()
{
	system("chcp 1251");


	//создаём граф
	Graph g;

	//добавляем вершины
	g.addVertex(Person("Олег")); //vertex 0
	g.addVertex(Person("Никита")); //vertex 1
	g.addVertex(Person("Настя")); //vertex 2
	g.addVertex(Person("Ваня")); //vertex 3
	g.addVertex(Person("Женя")); //vertex 4

	//добавляем связи
	g.addEdge(g.getVertex(0), g.getVertex(1));
	g.addEdge(g.getVertex(1), g.getVertex(2));
	g.addEdge(g.getVertex(2), g.getVertex(3));
	g.addEdge(g.getVertex(3), g.getVertex(4));

	//ищем длину связей и выводим на экран
	g.findMinDistancesFloyd();

	return 0;
}