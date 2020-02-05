//============================================================================
// Name        : graf.cpp
// Author      : Sofia Sautych
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

// размер матрицы
const int size = 7;

class Graph{
private:
	// метки обхода вершин
	bool* visited = new bool[size];
	vector<int> path = {};
	// матрица смежности
	int mSmezh[size][size] = {
			{0,1,0,0,1,0,1},
			{1,0,1,0,0,0,0},
			{0,1,0,1,1,0,0},
			{0,0,1,0,0,0,1},
			{1,0,1,0,0,1,0},
			{0,0,0,0,1,0,1},
			{1,0,0,1,0,1,0}
	};

public:
	Graph();
	~Graph();
	void printGraph(Graph*);
	void DFS(int,int,Graph*);

};

Graph::Graph(){};
Graph::~Graph(){};

void Graph::printGraph(Graph* newGr){
	cout << "Матрица смежности графа:" << endl;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			newGr->visited[i] = false;
			cout << " " << newGr->mSmezh[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Graph::DFS(int start, int end,Graph* newGr){
	newGr->visited[start] = true;
	for (int r = 0; r < size; r++){
		if((newGr->mSmezh[start][r] != 0)&&
			(!newGr->visited[r])){

			newGr->path.push_back(start + 1);
			newGr->DFS(r, end, newGr);
		}
		else if(start == end){
			for(unsigned int i = 0; i < newGr->path.size();i++){
				cout << newGr->path[i]  << " ";
			}
			cout<< end + 1 << endl;
			break;
		}
	}
}

int main() {
	int start = -1;
	int end = 5;

	//cout << "Введите значение начальной вершины" << endl;
	//cin >> start;
	//cout << "Введите значение конечной вершины" << endl;
	//cin >> end;

	if(size < start or size < end or start <= 0 or end <= 0){
		cout << "Неверное значение вершины." << endl;
	}
	else{
		Graph* newGr = new Graph;
		newGr->printGraph(newGr);
		cout<<"Порядок обхода: ";
		newGr->DFS(start - 1,end - 1,newGr);
		delete newGr;
	}

	return 0;
}
