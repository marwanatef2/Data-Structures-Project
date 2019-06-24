#include "Graph.h"

void graph::degree_centrality()
{
	// we just need to print values in no_of_connected_nodes vector
	for (auto itr = no_connected_nodes.begin(); itr != no_connected_nodes.end(); itr++)
	{
		cout << *itr << endl;
	}
}