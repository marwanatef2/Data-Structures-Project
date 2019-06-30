import networkx as nx
import matplotlib.pyplot as plt
from itertools import zip_longest
FileName1 = "undirected.txt"  # insert filename which contains nodes & edges
FileName2 = "centralityOutput.txt"  # insert filename which contain centrality
G = nx.read_edgelist(FileName1, create_using=nx.Graph(), nodetype=int)
#d = nx.read_edgelist(FileName2, create_using=nx.Graph(), nodetype=int)
#F = open(FileName2)
print(nx.info(G))
m = G.number_of_nodes()
temp_G = G.copy()
Z = nx.spring_layout(G)
with open(FileName2) as F:
    S = [float(row) for row in F]
# print (S)
for i in range(m):
    if S[i] == 0:
        sizevalue = 200
        # print('zero',sizevalue)
    elif S[i] > 0 and S[i] < 1:

        sizevalue = S[i]*3000
    else:
        sizevalue = S[i]*500
        # print('greater',sizevalue)
    nodes = nx.draw_networkx_nodes(temp_G, pos=Z, nodelist=[
                                   i], node_size=sizevalue)
labels = nx.draw_networkx_labels(temp_G, pos=Z)
edges = nx.draw_networkx_edges(temp_G, pos=Z, width=1)
plt.show()
