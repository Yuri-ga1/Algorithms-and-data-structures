import random

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def generate_binary_tree(depth):
    if depth == 0:
        return None

    total_nodes = 2 ** depth - 1

    def build_tree(value):
        if value >= total_nodes:
            return None

        node = Node(value)
        if(random.randint(1, 4) < 4):
            node.left = build_tree(2 * value + 1)
        if(random.randint(1, 4) < 4):
            node.right = build_tree(2 * value + 2)
        return node

    root = build_tree(0)
    return root

def save_tree(node):
    def serialize_node(node):
        if node is None:
            return '#'
        return str(node.value) + ' ' + serialize_node(node.left) + ' ' + serialize_node(node.right)

    tree = serialize_node(node)
    with open('tree.txt', "w") as file:
        file.write(tree)
    
depth = int(input('Максимальная глубина дерева: '))

random_tree = generate_binary_tree(depth)
save_tree(random_tree)
