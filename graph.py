import networkx as nx
import matplotlib.pyplot as plt
FileName1="undirected_unweighted_graph.txt"
FileName2="test.txt"
G = nx.read_edgelist(FileName1, create_using=nx.Graph(), nodetype=int)   #insert filename which contains nodes & edges
 #d = nx.read_edgelist(FileName2, create_using=nx.Graph(), nodetype=int)  #insert filename which contain centrality
F = open(FileName2)
print (nx.info(G))
m= G.number_of_nodes()
for i  in range (m):
    x = F.readline()
    S= int(x)
    temp_G= G.copy()
    nx.draw(temp_G, with_labels=True, font_weight='bold', node_size = S *300 ,nodelist=[i])
plt.show()


