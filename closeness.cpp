#include "Graph.h"
#include <queue>
#include <vector>
#include <list>
#include <iomanip>
#include <fstream>
void graph::shortest_Path_closeness(int source, vector<int> &shortest_distances)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_queue;

    p_queue.push({0, source});
    shortest_distances[source] = 0;

    list<pair<int, int>>::iterator it;

    while (!(p_queue.empty()))
    {

        int next_node = p_queue.top().second;
        int weight = p_queue.top().first;

        p_queue.pop();

        for (it = this->adjacency_list[next_node].begin(); it != this->adjacency_list[next_node].end(); it++)
        {

            int adj_node = it->first;
            int adj_node_weight = it->second;

            if (shortest_distances[adj_node] > shortest_distances[next_node] + adj_node_weight)
            {

                shortest_distances[adj_node] = shortest_distances[next_node] + adj_node_weight;
                p_queue.push({shortest_distances[adj_node], adj_node});
            }
        }
    }
}

void graph::closeness_centrality()
{

    ofstream myfile;
    myfile.open("C:\\Users\\zez\\Desktop\\finalproject\\Data-Structures-Project\\centralityOutput.txt");
    float sum;
    for (int k = 0; k < this->nodes_no; ++k)
    {
        sum = 0;
        vector<int> shortest_distances(this->nodes_no, 100000);
        this->shortest_Path_closeness(k, shortest_distances);
        // cout << "entering node " << k << endl;
        for (int i = 0; i < this->nodes_no; i++)
        {
            // cout << shortest_distances[i] << endl;
            sum += shortest_distances[i];
        }
        cout << setprecision(8) << (this->nodes_no - 1) / sum << endl;
        myfile << setprecision(8) << (this->nodes_no - 1) / sum << endl;
    }
    myfile << endl;
    myfile.close();
}