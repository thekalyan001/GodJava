package DataStructures;
 

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    public void insertAt(int ind, int data) {
        Node newNode = new Node(data);
        if (ind == 0) {
            newNode.next = head;
            head = newNode;
        } else {
            Node temp = head;
            for (int i = 0; i < ind - 1; i++) {
                temp = temp.next;
            }
            newNode.next = temp.next;
            temp.next = newNode;
        }
    }

    public void deleteAt(int ind) {
        Node temp = head, prev = null;
        for (int i = 0; i < ind-1; i++) {
            temp = temp.next;
        }
        prev = temp;
        temp = temp.next;
        prev.next = temp.next; 
    }
    public void show() {
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }
}
public class LinkList {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        list.insertAt(2, 13);
        list.show();
        list.deleteAt(2); 
        list.show();
    }
}