package DataStructures;
class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    public void insert(int data) {
        root = insertRec(root, data);
    }

    public Node insertRec(Node root, int data) {
        if (root == null)
            root = new Node(data);

        else if (data <= root.data)
            root.left = insertRec(root.left, data);

        else if (data > root.data)
            root.right = insertRec(root.right, data);

        return root;
    }

    public void inorder() {
        inorderRec(root);
    }

    public void inorderRec(Node root) { 
        if (root != null) { 
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }
}

public class TreeCode {

    public static void main(String[] args) {
        BinaryTree T = new BinaryTree();
        T.insert(40);
        T.insert(20);
        T.insert(30);
        T.insert(60);
        T.insert(50);
        T.insert(70);
        T.inorder();
        
    }
}
