package DataStructures;

class Stack {
    int capacity = 2;
    int stack[] = new int[capacity];
    int top = -1;

    //when there is full and still push called then we call resize
    private void resize() { 
        int currentLength = size();
        capacity = capacity * 2;
        int newStack[] = new int[capacity];
        System.arraycopy(stack, 0, newStack, 0, currentLength);
        stack = newStack;
    }

    public void push(int data) {
        if (size() == capacity)
            resize();

        stack[++top] = data;
    }

    //shrink- if after pop total number of element is goes below 3/4 than size of array make Half
    private void shrink() {
        int currentLength = size();
        if (currentLength < capacity / 4) {
            capacity = capacity / 2;
            int newStack[] = new int[capacity];
            System.arraycopy(stack, 0, newStack, 0, currentLength);
            stack = newStack;
        }
    }
    public int pop() {
        if (isEmpty() == true) {
            System.out.println("Stack is empty");
            return -1;
        }
        shrink();
        return stack[top--];
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        } 
        return stack[top];
    }

    public int size() {
        return top+1;
    }

    public boolean isEmpty() {
        return top == -1 ? true : false;
    }

    public void show() {
        for (int i = 0; i < capacity; i++) {
            System.out.print(stack[i]+" ");
        }System.out.println();
    }
    
}
public class StackCode{

    public static void main(String[] args) {

        Stack s = new Stack();
        s.push(10);
        s.show();
        s.push(20);
        s.show();
        s.push(30); 
        s.show();
    }
}