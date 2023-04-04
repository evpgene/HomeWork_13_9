#include "Graph.h"
#include <iostream>

Graph::Graph() {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = 0;
	vertexCount = 0;
}
Graph::~Graph() {};

// добавление вершины
void Graph::addVertex(const Person& person)
{
	vertexes[vertexCount] = person;
	vertexes[vertexCount++]._id = vertexCount;
}

// добавление ребра
void Graph::addEdge(const Person& person1, const Person& person2)
{
	matrix[person1._id][person2._id] = 1;
	matrix[person2._id][person1._id] = 1;
}

void Graph::delVertex(const Person& person)
{
	for (int i = 0; i < vertexCount; i++)
	{
		if (vertexes[i]._id == person._id)
		{
			for (int j = i + 1; j < vertexCount; j++)
			{
				vertexes[j - 1] = vertexes[j]; // возможно нужно перемещение
			}
			//vertexes[vertexCount] = 0; // проверить тут!!!
			vertexCount--;
			for (int j = 0; j < vertexCount; j++)
			{
				delEdge(vertexes[i], vertexes[j]);
			};
			break;
		}

	}
}

void Graph::delEdge(const Person& person1, const Person& person2)
{
	matrix[person1._id][person2._id] = 0;
	matrix[person2._id][person1._id] = 0;
}



// проверка существования ребра
bool Graph::edgeExists(const Person& person1, const Person& person2) const
{
	return matrix[person1._id][person2._id] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(const Person& person) const
{
	for (int i = 0; i < vertexCount; i++)
		if (vertexes[i]._id == person._id)
			return true;
	return false;
}



void Graph::findMinDistancesFloyd()
{
	int weights[SIZE][SIZE]; // матрица путей
	// инициализаци матрицы
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j)
			{
				weights[i][j] = 0; // путь до самой себя равен 0
			}
			else {
				if (!edgeExists(vertexes[i], vertexes[j]))
				{
					weights[i][j] = VERYBIGINT; // если ребра нет
				}
				else {
					weights[i][j] = matrix[i][j]; // если ребро есть
				}
			}
		}
	}

	for (int k = 0; k < vertexCount; k++) // итерации по k
	{
		int ck = vertexes[k]._id; // возьмем номер вершины
		for (int i = 0; i < vertexCount; i++)
		{
			if (i == k)
				continue;
			int ci = vertexes[i]._id;
			for (int j = 0; j < vertexCount; j++)
			{
				if (j == k)
					continue;
				int cj = vertexes[j]._id;
				if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
					// пересчет мматрицы путей
					weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
				}
			}
		}
	}

	// вывод всех пар с расстоянием не более 3
	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = 0; j < vertexCount; j++)
			if (weights[vertexes[i]._id][vertexes[j]._id] <= 3 && j != i)
				std::cout << vertexes[i]._name << " <-> " << vertexes[j]._name << ": " << weights[vertexes[i]._id][vertexes[j]._id] << ", " << std::endl;
		std::cout << std::endl;
	}

}

int Graph::getCount() const
{
	return vertexCount;
};

void Graph::printVertexes()
{
	for (size_t i = 0; i < vertexCount; i++)
	{
		std::cout << vertexes[i]._name << std::endl;
	}
};

Person Graph::getVertex(int id) const { return vertexes[id]; }


