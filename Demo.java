//class.forName()

public class Demo {

    public static void main(String[] args) throws InstantiationException, IllegalAccessException, ClassNotFoundException {
        
        Class.forName("Pqr").newInstance();
    
      
    }
}

class Pqr {
    static 
    {
        System.out.println("static block");
    }
    {
        System.out.println("in instance");
    }
}

/*
 * whenever we create an obj so before it will load the class and while loading it will call static Block
 * and while creating object it will call instance block.
 */