#include <iostream>
#include "Graph.h"


int main()
{
	system("chcp 1251");


	//������ ����
	Graph g;

	//��������� �������
	g.addVertex(Person("����")); //vertex 0
	g.addVertex(Person("������")); //vertex 1
	g.addVertex(Person("�����")); //vertex 2
	g.addVertex(Person("����")); //vertex 3
	g.addVertex(Person("����")); //vertex 4

	//��������� �����
	g.addEdge(g.getVertex(0), g.getVertex(1));
	g.addEdge(g.getVertex(1), g.getVertex(2));
	g.addEdge(g.getVertex(2), g.getVertex(3));
	g.addEdge(g.getVertex(3), g.getVertex(4));

	//���� ����� ������ � ������� �� �����
	g.findMinDistancesFloyd();

	return 0;
}