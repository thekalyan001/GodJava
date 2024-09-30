import java.util.LinkedList;
import java.util.Queue;

public class Demo{

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(10);
        queue.add(20);
        System.out.println("Front element is: " + queue.peek());
        System.out.println("Removed element: " + queue.remove());
        System.out.println("Queue after removal: " + queue);
        System.out.println("Is the queue empty? " + queue.isEmpty());

      
    }
}