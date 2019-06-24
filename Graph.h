#include <iostream>
#include <vector>
#include <list>

using namespace std;

#ifndef GRAPH
#define GRAPH

class graph
{
public:
	graph(int no_nodes)
	{
		//resize the vector to fit the no of given nodes
		adjacency_list.resize(no_nodes);
		no_connected_nodes.resize(no_nodes);
	}

	void add_edge(int node1, int node2, int weight)
	{
		// since it is undirected graph, nodes are added in both lists
		adjacency_list[node1].push_back({ node2, weight });
		adjacency_list[node2].push_back({ node1, weight });
		//incrementing no of nodes in each list to get "DEGREE CENTRALITY"
		no_connected_nodes[node1]++;
		no_connected_nodes[node2]++;
	}

	void degree_centrality();
	void closeness_centrality();
	void betweeness_centrality();

private:
	/*
	adjacency list stores nodes in a vector of lists 
	where each index resembles a node
	lists of pairs to indicate an edge with node x & weight y

	-----------------------------------------------------------


	node_index   (node_index, edge_weight),...
	0:			 (1,5), (2,10), (3,6)
	1:			 (0,5), (3,8)
	2:			 (1,10)
	3:			 (0,6), (1,8)
	*/

	vector<list<pair<int, int>>> adjacency_list;
	vector<int> no_connected_nodes;
};


#endif // !GRAPH



