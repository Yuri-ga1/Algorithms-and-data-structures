import matplotlib.pyplot as plt
import networkx as nx

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def load_tree(filename):
    def deserialize_node(data):
        if data[0] == '#':
            data.pop(0)
            return None
        
        value = int(data[0])
        node = Node(value)
        data.pop(0)
        node.left = deserialize_node(data)
        node.right = deserialize_node(data)
        return node
    
    with open(filename, 'r') as file:
        _tree = file.read().split()
    tree = deserialize_node(_tree)
    return tree

def draw_binary_tree(node):
    G = nx.Graph()

    def add_edges(node, parent=None):
        if node is None:
            return

        G.add_node(node.value)
        if parent is not None:
            G.add_edge(parent, node.value)

        add_edges(node.left, node.value)
        add_edges(node.right, node.value)

    add_edges(node)
    #pos = nx.drawing.nx_pydot.graphviz_layout(G, prog='dot')
    nx.draw(G, with_labels=True, node_size=500, node_color='lightblue')
    plt.show()

def isfull(node):
    if node is None:
        return True
    if node.left is None and node.right is None:
        return True
    if node.left is not None and node.right is not None:
        return isfull(node.left) and isfull(node.right)
    return False

def iscomplete(node, total, idx=0):
    if node is None:
        return True
    if idx >= total:
        return False
    return iscomplete(node.left, 2 * idx + 1, total) and iscomplete(node.right, 2 * idx + 2, total)

def get_tree_depth(node):
    if node is None:
        return 0
    return max(get_tree_depth(node.left), get_tree_depth(node.right)) + 1

def preorder(node):
    if node is None:
        return []
    return [node.value] + preorder(node.left) + preorder(node.right)

def inorder(node):
    if node is None:
        return []
    return inorder(node.left) + [node.value] + inorder(node.right)

def postorder(node):
    if node is None:
        return []
    return postorder(node.left) + postorder(node.right) + [node.value]


tree = load_tree('tree.txt')
depth = get_tree_depth(tree)

print("Строгое дерево:", iscomplete(tree, depth))
print("Полнотое дерево:", isfull(tree))
print("Глубина:", depth)
print("Preorder:", preorder(tree))
print("Inoerder:", inorder(tree))
print("Postorder", postorder(tree))
draw_binary_tree(tree)