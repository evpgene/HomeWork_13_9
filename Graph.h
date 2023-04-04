#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000 // ����� ������� �����
#include "Person.h"
#include <vector>

class Graph
{
public:
	Graph();
	~Graph();
	
	void addVertex(const Person& person);// ���������� �������
	void addEdge(const Person& person1, const Person& person2);// ���������� �����
	void delVertex(const Person& person);// �������� �������
	void delEdge(const Person& person1, const Person& person2);// �������� �����

	void findMinDistancesFloyd(); //����� ������������ ���� �������� ������-��������

	int getCount() const;
	void printVertexes();
	Person getVertex(int id) const;
	bool edgeExists(const Person& person1, const Person& person2) const;
	bool vertexExists(const Person& person) const;

private:
	Person vertexes[SIZE]; // ��������� ������
	int matrix[SIZE][SIZE]; // ������� ���������
	int vertexCount; // ���������� ����������� ������
};

