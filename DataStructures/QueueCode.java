package DataStructures;
class Queue {
    int len = 3;
    int queue[] = new int[len];
    int size, front, rear;


    public void enQueue(int data) {
        if (!isFull()) {
            queue[rear] = data;
            rear = (rear + 1) % len;
            size = size + 1;
        }
        else
            System.out.println("Queue is full");
    }

    public int deQueue() {
        int data = queue[front];
        if (!isEmpty())
        {
            front = (front + 1) % len;
            size = size - 1;
        }
        else
            System.out.println("Queue is empty");
        return data;
    }

    public void show() {
        System.out.println("Elements: ");
        for (int i = 0; i < size; i++) {
            System.out.print(queue[(front + i) % len] + " ");
        }
        System.out.println();
    }

    public int getSize() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {        
        return size == len;
    }
}
public class QueueCode {
    public static void main(String[] args) {
        Queue Q = new Queue();
        Q.enQueue(4);
        Q.enQueue(5);
        Q.enQueue(7);
        Q.enQueue(8);
        Q.show();
        Q.deQueue();
        Q.show();
    }
}
