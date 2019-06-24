#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main() {

	// reading test cases from text file instead of terminal
	ifstream input("testcases.txt");
	cin.rdbuf(input.rdbuf());

	int no_testcases;
	cin >> no_testcases;

	// for each test case do the following
	while (no_testcases--)
	{
		int no_vertices, no_edges;
		cin >> no_vertices >> no_edges;
		//initialize myGraph with the given no of vertices
		graph myGraph(no_vertices);

		while (no_edges--)
		{
			int vertex1, vertex2, edge_weight;
			cin >> vertex1 >> vertex2 >> edge_weight;
			myGraph.add_edge(vertex1, vertex2, edge_weight);
		}

		char centrality;
		cin >> centrality;
		if (centrality == 'b')
			myGraph.betweeness_centrality();
		else if (centrality == 'c')
			myGraph.closeness_centrality();
		else
			myGraph.degree_centrality();

		cout << endl;
	}

	return 0;
}