class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        new_node = Node(key)
        if self.root is None:
            self.root = new_node
            return self.root
        else:
            current = self.root
            while True:
                if key == current.val:
                    print(f"Duplicate entry {key} ignored.")
                    return self.root
                elif key < current.val:
                    if current.left is None:
                        current.left = new_node
                        return self.root
                    current = current.left
                else:
                    if current.right is None:
                        current.right = new_node
                        return self.root
                    current = current.right

    def search(self, key):
        current = self.root
        while current:
            if current.val == key:
                return current
            elif key < current.val:
                current = current.left
            else:
                current = current.right
        return None

    def delete(self, root, key):
        if root is None:
            print("Tree is Empty.")
            return root

        current = root
        parent = None

        while current and current.val != key:
            parent = current
            if key < current.val:
                current = current.left
            else:
                current = current.right

        if current is None:
            print(f"Key {key} not found in the tree.")
            return root

        # Case 1: Node has no children
        if current.left is None and current.right is None:
            if current == root:
                return None
            if parent.left == current:
                parent.left = None
            else:
                parent.right = None

        # Case 2: Node has one child
        elif current.left is None or current.right is None:
            child = current.left if current.left else current.right
            if current == root:
                return child
            if parent.left == current:
                parent.left = child
            else:
                parent.right = child

        # Case 3: Node has two children
        else:
            successor_parent = current
            successor = current.right
            while successor.left:
                successor_parent = successor
                successor = successor.left
            current.val = successor.val
            if successor_parent.left == successor:
                successor_parent.left = successor.right
            else:
                successor_parent.right = successor.right

        return root

    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.val, end=' ')
            self.inorder(root.right)

    def preorder(self, root):
        if root:
            print(root.val, end=' ')
            self.preorder(root.left)
            self.preorder(root.right)

    def postorder(self, root):
        if root:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.val, end=' ')

    def level_order(self, root):
        if not root:
            return []
        queue = [root]
        result = []
        while queue:
            current = queue.pop(0)
            result.append(current.val)
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        return result

    def height(self, node):
        if node is None:
            return -1
        left_height = self.height(node.left)
        right_height = self.height(node.right)
        return max(left_height, right_height) + 1

    def mirror(self, root):
        if root:
            root.left, root.right = root.right, root.left
            self.mirror(root.left)
            self.mirror(root.right)

    def copy(self, root):
        if root is None:
            return None
        new_node = Node(root.val)
        new_node.left = self.copy(root.left)
        new_node.right = self.copy(root.right)
        return new_node

    def display_leaf_nodes(self, root):
        if root is None:
            return
        if root.left is None and root.right is None:
            print(root.val, end=' ')
        self.display_leaf_nodes(root.left)
        self.display_leaf_nodes(root.right)

    def display_parent_child(self, root):
        if root:
            if root.left:
                print(f"Parent {root.val} -> Left Child {root.left.val}")
            if root.right:
                print(f"Parent {root.val} -> Right Child {root.right.val}")
            self.display_parent_child(root.left)
            self.display_parent_child(root.right)


def main():
    bst = BST()
    while True:
        print("\n-----------Binary Search Tree Operations-----------")
        print("1. Insert")
        print("2. Search")
        print("3. Delete")
        print("4. Inorder Traversal")
        print("5. Preorder Traversal")
        print("6. Postorder Traversal")
        print("7. Level Order Traversal")
        print("8. Height of Tree")
        print("9. Mirror Tree")
        print("10. Copy Tree")
        print("11. Display Parent-Child Nodes")
        print("12. Display Leaf Nodes")
        print("13. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            key = int(input("Enter value to insert: "))
            bst.root = bst.insert(key)

        elif choice == 2:
            key = int(input("Enter value to search: "))
            result = bst.search(key)
            if result:
                print(f"Found: {result.val}")
            else:
                print("Not found.")

        elif choice == 3:
            key = int(input("Enter value to delete: "))
            bst.root = bst.delete(bst.root, key)

        elif choice == 4:
            print("Inorder Traversal:", end=' ')
            bst.inorder(bst.root)
            print()

        elif choice == 5:
            print("Preorder Traversal:", end=' ')
            bst.preorder(bst.root)
            print()

        elif choice == 6:
            print("Postorder Traversal:", end=' ')
            bst.postorder(bst.root)
            print()

        elif choice == 7:
            print("Level Order Traversal:", bst.level_order(bst.root))

        elif choice == 8:
            height = bst.height(bst.root)
            print(f"Height of the tree: {height}")

        elif choice == 9:
            bst.mirror(bst.root)
            print("Tree mirrored.")

        elif choice == 10:
            copy_root = bst.copy(bst.root)
            print("Tree copied. Inorder traversal of copy:", end=' ')
            bst.inorder(copy_root)
            print()

        elif choice == 11:
            print("Parent -> Child relations:")
            bst.display_parent_child(bst.root)

        elif choice == 12:
            print("Leaf Nodes:", end=' ')
            bst.display_leaf_nodes(bst.root)
            print()

        elif choice == 13:
            print("Exiting...")
            break

        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main()
