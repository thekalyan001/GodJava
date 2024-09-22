import java.util.Objects;

class Alien {
    private final int id;
    private final String name;

    public Alien(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }
 

    // equal method behaviour change to check if value same then ob is same.
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Alien alien = (Alien) obj;
        return id == alien.id && Objects.equals(name, alien.name);
    }

    // this is when we print objects
    @Override
    public String toString() {
        return "Alien [id=" + id + ", name=" + name + "]";
    }
    
    
    
    
}
// record Alien(int id, String name) {

// } 

public class Demo {
    public static void main(String[] args) {
        Alien ob1 = new Alien(1, "Zorg");
        Alien ob2 = new Alien(1, "Zorg");

        System.out.println(ob1.getName());
        System.out.println(ob1);
        System.out.println(ob1.equals(ob2));
    }
}