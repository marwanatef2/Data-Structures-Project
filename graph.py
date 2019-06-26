
import networkx as nx
import matplotlib.pyplot as plt
FielName1="undirected_unweighted_graph.txt"
FielName2="test.txt"
G = nx.read_edgelist(FielName1, create_using=nx.Graph(), nodetype=int)
d = nx.read_edgelist(FielName2, create_using=nx.Graph(), nodetype=int)

print (nx.info(G))
nx.draw(G,with_labels=True, font_weight='bold')
plt.show()

