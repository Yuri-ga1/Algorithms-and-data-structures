import matplotlib.pyplot as plt
import networkx as nx
import os

def build_tree(directory_path, G=None, parent=None):
    if G is None:
        G = nx.DiGraph()

    if parent is None:
        G.add_node(directory_path, name=os.path.basename(directory_path))
    else:
        G.add_node(directory_path, name=os.path.basename(directory_path))
        G.add_edge(parent, directory_path)

    if os.path.isdir(directory_path):
        entries = os.listdir(directory_path)
        for entry in entries:
            full_path = os.path.join(directory_path, entry)
            build_tree(full_path, G, directory_path)

    return G

data = input()[:-2]
#data = "1.3220701217651367 ['65057b.wav', '04233b.wav', '0935db.wav', '214bcb.wav', '2c9558.wav', '393110.wav', '6972e7.wav', '7d818a.wav', '9258ca.wav', '9658de.wav', 'b18d91.wav', 'aa0d74.wav', 'b6717c.wav', '08f4aa.wav', '0f5cab.wav', 'dd1c1f.wav"
data_splited = data.split(' [\'')
time = float(data_splited.pop(0))
dublicates = str(data_splited)[2:-2].split('\', \'')

root_directory = 'samples'

G = build_tree(root_directory)

#pos = nx.drawing.nx_pydot.graphviz_layout(G, prog='dot')
labels = nx.get_node_attributes(G, 'name')

node_colors=[]
for node in G.nodes:
    try:
        if dublicates.index(node[-10:])>-1:
            node_colors.append('red')
    except:
        node_colors.append('lightblue')

plt.figure(figsize=(12, 8))
nx.draw_networkx(G, with_labels=True, labels=labels, node_size=1000, node_color=node_colors, edge_color='gray')
plt.axis('off')
plt.show()