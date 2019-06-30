#include "Graph.h"
#include <fstream>
void graph::degree_centrality()
{
	ofstream myfile;
	myfile.open("C:\\Users\\zez\\Desktop\\finalproject\\Data-Structures-Project\\Grappph\\centralityOutput.txt");
	// we just need to print values in no_of_connected_nodes vector
	for (auto itr = no_connected_nodes.begin(); itr != no_connected_nodes.end(); itr++)
	{
		cout << *itr << endl;
		myfile << *itr << endl;
	}
	myfile << endl;
	myfile.close();
}