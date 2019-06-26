
import networkx as nx
import matplotlib.pyplot as plt
FielName1="undirected_unweighted_graph.txt" #insert filename which contains nodes & edges
FielName2="test.txt"                       #insert filename which contain centrality
G = nx.read_edgelist(FielName1, create_using=nx.Graph(), nodetype=int)
d = nx.read_edgelist(FielName2, create_using=nx.Graph(), nodetype=int)

print (nx.info(G))
nx.draw(G,with_labels=True, font_weight='bold') #editing nodesize will be added
plt.show()

