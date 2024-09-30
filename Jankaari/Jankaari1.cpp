Install Java,  Install Maven, Install vs code.
Install necessary extension for java in vscode
vscode:extension/vscjava.vscode-java-pack

Demo.Java
public class Demo
--Compile  javac Demo.java
--run java Demo

Using single command- java Demo.java
Do using single line compile and run
    -- javac Demo.java; java Demo

Multiple inheritance in java doesnt work:- 
suppose we have method y() in both class A and B  and if we call
the y() from C then it will get confused which class method to call.
class A{}
class B{}

class C extends A,B{}

}


----------------Packages------
A package is a collection of classes & files. it is a grouping of classes which are related.
like some class in folder and many such folder in Another parent folder called package.
eg:- we have folder

CALCULATOR
    tools
        |   AdvCalc.java
        |   Calc.java
    Demo.java

Demo.java   
    import tools.Calc
    import tools.AdvCalc
    import java.util.ArrayList;

    public class Demo{
        public static void main(String[] args) {
            ArrayList arr = new ArrayList();
            Calc obj= new Calc();
            System.out.println(obj.sum(2,3));
        }
    }

💡 we always have to create unique package for internet.
    so we use reverse domain name of company.  
        com.example.tools
        com.google.calcualtor


--------------------------access modefier----public, default, private, protected
by default it is type Default (can be accessed in same package)

sub class means class which extends the Parent wala (in which we ve var/fn)

 can access                    public      private  protected  Default
same class                      yes         yes       yes       yes
same pkg subclass               yes         no        yes       yes
same pkg non-sub class          yes         no        yes       yes
Different pkg subclass          yes         no        yes       no
Different pkg non-sub class     yes         no        no        no


Some best practices:- (avoide default)
Keep class as public
instence variable as private
methods as public (if u want method to be used only in subclass of other pkgs then make it protected)


---------------------------Polymorphism------
behave Differently in Different situation
Compile time- (early binding)   runtime-(late binding)
    overloading                         overriding
add(int,int)                            add(int,int)
add(int,int,int)                        add(int,int)

//if we print object then it implicitly calls the object's toString() method by default  in java so we can override in class to do something else.
eg:
class Student { 
     @Override
    public String toString() {
        return "toString method called";
    }
}



💡 subclass as obj of superclass
class Computer{}
class Laptop extends Computer{}
public class Main(){
    public static void main(String[] args) {
        Computer obj= new Computer();
        Computer obj1= new Laptop();  // yes we can have subclass as type of Super class
    }
}


-------Dynamic method dispatch---------(run time Polymorphism) 7:08:00
class A{
    public void show(){sout("in A"); } 
}
class B extends A{
    public void show(){sout("in A"); } 
}
public class Main(){
    public static void main(String[] args) {
        A obj= new A();
        obj.show();

        obj= new B();  // yes we can assign obj to different class type (But that should extend that parent)
        obj.show();
    }
}

👉we can assign obj to different class type (But that should extend that parent).

so if we see obj.show then we cant say which class show() will be called its decided
at run time.  This overall is called Dynamic method dispatch.



----------Final keyword- (can used for variable, method, class)
Variale which doesnt change- (eg- pie 3.14)
Final class Calc  ->so this class cant inherit. no one can extend it.
public final void show() ->this method cant override in child class.

---------7.41.00  Wrapper class
For premitive data type it doesn't extends from Object class.
which makes java 99.9% obj oridned language.  But other collection comes from Object class.

we have concept of Wraper class which is object class for these premitive data type.

int ->Integer
char->Character
double->Double
.
.
etc

int num=6
Integer num1= new Integer(6); deprecated syntax // boxing - assgining premitive data type to object class
Integer num1 = 6; // this also use concept of auto boxing, back the scene, automatically converting.

int num2 = num1.intValue(); // unboxing
int num2 = num1; // auto unboxing

----------------Abstract keyword---------
We cant create obj of abstrct class. 
abstract class may or may not be abstract method.
if there is abstract method than Child which inherit must implement that method.

abstract class Car {     //abstract class
    public abstract void drive();

    public void playMusic() {
        System.out.println("Playing Music");
    }
}

class Tesla extends Car {  //concreate class- which extends abstract class
    public void drive() {
        System.out.println("Driving");
    }
    
}

public class Demo {
    public static void main(String[] args) {
        Car obj = new Tesla();  //Dynamic method dispatch line 82  (up casting)
        obj.drive();
        obj.playMusic();
    }
}

--------------8:01:30 Inner class  (class inside class)
class A {
    int age;

    public void show() {
        System.out.println("hello");
    }

    class B
    {
        public void config() {
            System.out.println("in config");
        }
    }
}

public class Demo {
    public static void main(String[] args) {
        A obj = new A();
        obj.show();

        A.B obj1 = obj.new B();  // B belong to A class, using A obj we can crete B obj.
        obj1.config();

        // static class B  then we can => A.B obj1 = new A.B();
    }
}


---------------Anonymous inner class------------
class A {
    public void show() {
        System.out.println("in A show");
    }
}

public class Demo {
    public static void main(String[] args) {
        A obj = new A(){  //anonymous inner class- we gave own implementatio of show, its syntax without class name
            public void show() {
                System.out.println("in anonymous class show");
            }
        };
        obj.show();
    }
}



---abstract class anonymous class  (8:12:40)
abstract class A 
    public void show() {
        System.out.println("in A show");
    }

    
    public void show1() {
        System.out.println("in AAA show");
    }
}

public class Demo {
    public static void main(String[] args) {
        A obj = new A(){
            public void show() {
                System.out.println("in anonymous class show");
            }
        };
        obj.show1();  //this is bcoz we have created new anonymous class which extends the class A(abstract class) thats why
    }
}

-------------------------- Interface 8:15:00

->Interface is a design and it only tells which methods you need but your job is to implement that.
->all varialbe in Interface are Final and static.
->A class can implements Multiple interfaces, where as c class can't extends multiple abstract class.
-> .class - class ->extends
   .class - interface ->implements
   .interface - interface ->extends


When we have abstract class which has only abstract methods so we should create that as Interface.
method inside interface can't have body. (By default every mehod in interface has public abstract)


abstract class Computer {
    public abstract void code();
} 
class Laptop extends Computer {
    public void code() {
        System.out.println("laptop coding");
    }
}

class Desktop extends Computer {
    public void code() {
        System.out.println("Desktop coding");
    }
}

public class Demo {
    public static void main(String[] args) {
        Computer lap = new Laptop();   //this is interface type obj
        Computer desk = new Desktop();
        lap.code();
        desk.code();
    }
}

converting above to Interface   (remove abstract and replace extends->implements)
else all code is same.


interface Computer {
    void code();  //here public abstract is there behind the scene
}
class Laptop implements Computer {
    //same code here
}
 
class Desktop implements Computer {
    //same code here
}
 //...same code..
 

 ---------------------------Enums-8:30:00---------
 Eg- uses in error codes (server erorr codes status)
 enum Status{  // in Java everything is class, this also
     Success,  // these are objects of class enum
     Failure,
     Pending,
     Running,
 }
public class Demo{
    public static void main(String[] args) {
        Status[] ss = Status.values();
        for(Status s : ss) {
            System.out.println(s);
        }
    }
}

8:53:49 - implementation of enum, object, private construtor etc.

--------------------------@Annotations🥂🥂-------------
We supply some extra info to compilercompiler, or a metadata- 

see below example->if you remove override than it wont gve you context that youre override different method whihc is in class A
but when you put override than it will give you error that function name is not same, in A class.
class A{
    public void OverrideTheMethodPresentInAClass() {
        System.out.println("In A Show");
    }
}

class B extends A { 
    @Override
    public void OverrideTheMethodsPresentInAClass() {
        System.out.println("In B Show");
    }
}

public class Demo {
    public static void main(String[] args) {
        B obj = new B();
        obj.OverrideTheMethodPresentInAClass();        
    }

}


@Override  ->we tell the compiler that this method is overriden.


-----------Types of interfaces---09:08:00---------(by default interface is public abstract, it has only fn declaration)
1. Normal interface  (2 or more methods)
2. Functional/SAM Interface  (Sam- single abstract method -only 1 method)
3. Marker interface (no method or blank interface, we tell compiler to allow someting) 


@FunctionalInterface
interface A {
    void show();
    void show1();  //it will give error that @Functioninterface nnotantion should have only 1 fn
}

@FunctionalInterface
interface A {
    void show(int n);
}

class B implements A {  //to use interface A we created this class
    public void show(int n) {
        System.out.println("Hello: "+n);
    }
}

public class Demo {
    public static void main(String[] args) {
        B obj = new B();
        obj.show(4);
    }
}

->we can also avoid to create class and use interface.

@FunctionalInterface
interface A {
    void show(int n);
}
public class Demo {
    public static void main(String[] args) {
        A obj = new A(){
            public void show(int n){
               System.out.println("Hello: "+n);
            }
        };
        obj.show(4);
    }
}

💡->we can also make ths as lambda expression.(Functional interface only, as it has only 1 fun)

@FunctionalInterface
interface A {
    void show(int n);
}
public class Demo {
    public static void main(String[] args) {
        A obj =  (int n)->{
                System.out.println("Hello: "+n); 
        };
      
        obj.show(6);
    }
}

->we can also make it one liner
        A obj =  (int n)-> System.out.println("Hello: "+n); 
        we can also
        A obj =  (n)-> System.out.println("Hello: "+n);
        we can also
        A obj = n-> System.out.println("Hello: "+n);  

        🥂😱



------------🔥Return from the lambda function.
@FunctionalInterface
interface A {
    int add(int i, int j);
}

public class Demo {

    public static void main(String[] args) {
        A obj = new A(){
            public int add(int i, int j){
                return i+j;
            }
        };
        int res = obj.add(3, 3);
        System.out.println(res);
    }
}

-> we can also use lambda Exp.
     A obj = (i,j)->{
        return i+j;
     };

->we can also write
    A obj = (i,j)->i+j;




----------------------Exceptions 09:18:00

1. Comple time   2. Logical err  3. Run time

Comple time eg->system.out.PrintLn(); 
Logical ->not expected output
Run time->out of memory, stack overflow; 
try{

}catch(Exceptions e){
    
}

Arthematic exception, ArrayIndexOutOfBound, 


---------------------10:03:00  Taking input from user 🤡--------
1569 years ago--
public static void main(String[] args) throws NumberFormatException, IOException {

        System.out.println("Input a number");

        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader bf = new BufferedReader(in);
        int num = Integer.parseInt(bf.readLine());
        System.out.println(num);
        bf.close();
    }

----------Now 🤡
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        System.out.println(num);
        sc.close();
    }


try{

}catch(){

}finally{
    //this block will execute irrespective of error or not.
    this used to close Resource, File, network, db,connection.
}


int num =0 ;
BufferedReader bf = null;

try{
    bf=new BufferedReader(new InputStreamReader(System.in));
    num = Integer.parseInt(bf.readLine());
    System.out.println(num);
}
finally{
    bf.close();
}



---try with Resources---------Better way (we can also pass in try() block and it will auto close as bufferReader is autoClocable, no need finally).
int num=0;
try(BufferedReader bf = new BufferedReader(new InputStreamReader(System.in))) {
    num = Integer.parseInt(bf.readLine());
    System.out.println(num);
}


-------------------------10:23:00 🧵 Threads---------
Multiple things happening at same time.

extend class from Thread, and use start() function to start thread and thread calls 
run() function, 'run() fn keyword is for Thread'

Priprity: by default priotiry is notmal, but we can change it using setPriority() method.
System.out.println(obj1.getPriority());  //5

Observe here 👇🏻 Thread are running parallel, overlapping
class A extends Thread {
    public void run() {
        for(int i=0;i<50;i++){
            System.out.println("Aloo");            
        }
    }
}

class B extends Thread {
    public void run() {
        for(int i=0;i<50;i++){
            System.out.println("Bello");            
        }
    }
}
public class Demo{
    public static void main(String[] args) {
        A obj1 = new A();
        B obj2 = new B();
 
        obj1.start();
        obj2.start();
    }
}

--------------get thread Priprity
priority is from 0 to 10, 10 is max priority, 0 is lowest priority.
System.out.println(obj1.getPriority());


----ser priotiry------
Different schedulers are there so some finish thread with less time, some finish thread having with more time.
we're just suggesting by adding priority that run obj2.

    public static void main(String[] args) {
        A obj1 = new A();
        B obj2 = new B();
        
        obj2.setPriority(Thread.MAX_PRIORITY);  // MAX_PRIORITY=10, for 9=>MAX_PRIOTIRY-1 

        obj1.start();
        obj2.start();
    }



-----while printing, we can make this wait using sleep();
it will goto waiting stage.

Thread.sleep(10);  //wait for 10 milisec, this will put Interrupted Exception.

Observe here 👇🏻   (It will print in sequence by waiting for some milisec)
class A extends Thread {
    public void run() {
        for(int i=0;i<50;i++){
            System.out.println("Aloo");
            
            try{
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class B extends Thread {
    public void run() {
        for(int i=0;i<50;i++){
            System.out.println("Bello");
            
            try{
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
public class Demo{
    public static void main(String[] args) {
        A obj1 = new A();
        B obj2 = new B();
        
        obj2.setPriority(Thread.MAX_PRIORITY);

        obj1.start();
        obj2.start();
    }
}


------------other option to make Thread (Suppose when class A want to extend other parent class)
bY Runnable interface. ( its interface) it doest have start() function, but Thread class have start() function.

class A implements Runnable {
    public void run() {
        for(int i=0;i<=5;i++){
            System.out.println("Aloo");
            
            try{
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class B implements Runnable {
    public void run() {
        for(int i=0;i<=5;i++){
            System.out.println("Bello");
            
            try{
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
public class Demo{
    public static void main(String[] args) {
        Runnable obj1 = new A();  //Runnable instance and object of A
        Runnable obj2 = new B();

        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);

        t1.start();
        t2.start();
    }
}

------convert this above into anonymous class and reduce code---Lambda 🤡
we're creating class A to extend runnable, so just create anonymous Runnable.

 
public class Demo{
    public static void main(String[] args) {
        Runnable obj1 = new Runnable() {
            public void run() {
                for(int i=0;i<=5;i++){
                    System.out.println("Aloo");
                    
                    try{
                        Thread.sleep(10);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };


        Runnable obj2 = new Runnable() {
            public void run() {
                for(int i=0;i<=5;i++){
                    System.out.println("Bello");
                    
                    try{
                        Thread.sleep(10);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);

        t1.start();
        t2.start();
    }
}

🤡 Lambda can be used in functional Interface, so ctrl+click Runnable is f/n interface.

 
public class Demo{
    public static void main(String[] args) {
        Runnable obj1 = () -> 
            {
                for(int i=0;i<=5;i++){
                    System.out.println("Aloo");

                    try { Thread.sleep(10); } catch (InterruptedException e) { e.printStackTrace();}
                }

            };


        Runnable obj2 = ()->
            {
                for(int i=0;i<=5;i++){
                    System.out.println("Bello");
                    
                    try { Thread.sleep(10); } catch (InterruptedException e) { e.printStackTrace();}
                }
            };
        

        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);

        t1.start();
        t2.start();
    }
}

Wooho 🎉



------------------Race Condition 🏃🏻‍♀️🏃🏻‍♂️ 10:56:00

Mutation- means we can change something.
Thread + mutation => thread can mutate each other.

Thread Safe -> only one thread can work at one point.


Using Join() method we can make main() thread wait for other method to come back and join.
 
class Counter {
    int count;

    public void increment() {
        count++;
    }
}


public class Demo {   
    public static void main(String[] args) {
        Counter c = new Counter();
        Runnable obj1 = () -> {
            for (int i = 1; i <=1000; i++) {
                c.increment();
            }
        };

        Runnable obj2 = () -> {
            for (int i = 1; i <=1000; i++) {
                c.increment();
            }   
        };

        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);

        t1.start();
        t2.start();

        try {
            t1.join(); // Wait for t1 to finish
            t2.join(); // Wait for t2 to finish
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(c.count);
    }
}


Create two thread and make them synchronised to run one by one. (one thread run at a time).
so we'll get all the value in that case.

public synchronized void increment() {
        count++;
}



----------------------Different stated of thread.----------
New State, Runnable state, Waiting, Running, Dead.

New state- start() method called.
Runnable()- when our thread is executing but waiting for scheduler.
Running()- when our thread if running on cpu.
wait() - go into waiting state.  Comeback using notify()- it will take into Runnable state.
Dead() - stop()  //but its deprecated.


-----------------------------Collection 👩🏻📁🗄
Collection Api- Means concept-  it have all the data structures
Collection - means interface
Collections - means class, have multiple method to work with

Iterable
   --Collection
        --List - (ArrayList, LinkedList)
        --Queue - (Dequeue)
        --Set - (HashSet, LinkedHashSet, TreeSet)

💡 we can also write Collection instead of its List, Queue, Set, ArrayList, LinkedList

By Default Collection Api extends objects.

import java.util.Collection;
import java.util.ArrayList; 
public static void main(String[] args) {
        Collection nums = new ArrayList();
        nums.add(10);
        nums.add(20);
        nums.add(30);

        for (int n : nums) //❌ this is error as type of collection is object
            System.out.println(n);

        System.out.println(nums);
    }

AS by default type is object 
So to store the type like Integer we use generic. use <> and give type

Collection<Integer> nums = new ArrayList<Integer>();


import java.util.Collection;
import java.util.List;  
import java.util.ArrayList;  
public class Demo {   
    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<Integer>();
        nums.add(10);
        nums.add(20);
        nums.add(30);

        for (int n : nums)
            System.out.println(n);

        System.out.println(nums);
        System.out.println(nums.get(1));
        System.out.println(nums.indexOf(1));
    }
}


Iterable
   --Collection
        --List - (ArrayList, LinkedList)
        --Queue - (Dequeue)
        --Set - (HashSet (unsorted), TreeSet (sorted value), LinkedHashSet)

Collection<Integer> nums = new ArrayList<Integer>();✔
List<Integer>nums = new ArrayList<Integer>(); ✔

-----------11:35:29--On Top most we have Iterator, so we can iterate the collection

import java.util.Collection;
import java.util.Iterator;
import java.util.TreeSet; 
public class Demo {   
    public static void main(String[] args) {
        Collection<Integer> nums = new TreeSet<Integer>();
 
        nums.add(1);
        nums.add(230);
        nums.add(20);
        nums.add(220);
         
        Iterator<Integer> it = nums.iterator();
        while(it.hasNext()) {
            System.out.println(it.next());
        }
    }
}


---11:40:00-- MAP -> instead of index we can have index as name based on key value

import java.util.HashMap;
import java.util.Map; 
public class Demo {   
    public static void main(String[] args) {
        Map<String, Integer> mp = new HashMap<>();
        mp.put("Kalyan", 23);
        mp.put("Gungun", 22);
        mp.put("Harneet", 27);
        mp.put("Naveen", 23);
        System.out.println(mp);
        System.out.println(mp.get("Gungun"));

        System.out.println(mp.keySet());  //click on ctrl+click on map and see multiple methods inside that.
        System.out.println(mp.values());

        for (String name : mp.keySet()) {
            System.out.println(name + " " + mp.get(name));
        }
    }
}



---------------Collections
---sorting-

import java.util.ArrayList;
import java.util.List;
import java.util.Collections; 
public class Demo {   
    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<>();
        nums.add( 23);
        nums.add( 22);
        nums.add(27);
        nums.add( 24);
        Collections.sort(nums);

        System.out.println(nums);
    }
}


---sort based on Comperator-
public static void main(String[] args) {

        Comparator<Integer>comp = new Comparator<Integer>() {
            public int compare(Integer i, Integer j) {
                if(i%10 > j%10)
                    return 1;
                else
                    return -1;
            }
        };

        List<Integer> nums = new ArrayList<>();
        nums.add( 43);
        nums.add( 31);
        nums.add(72);
        nums.add( 29);
        Collections.sort(nums, comp);

        System.out.println(nums);
    }


--------------Sort comparator based on Student class ✔.
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.Collections;
import java.util.Comparator;

class Student {
    int age;
    String name;
 
    public Student(int age, String name) {
        this.age = age;
        this.name = name;
    }

    //printing object  it implicitly calls the object's toString() method by default  in java so we can override in class to do something else.
    @Override
    public String toString() {
        return "Student [age=" + age + ", name=" + name + "]";
    }
}
public class Demo {   
    public static void main(String[] args) {

        Comparator<Student>comp = new Comparator<Student>() {
            public int compare(Student i, Student j) {
                if(i.age>j.age)
                    return 1;
                else 
                return -1;
            }
        };

        List<Student> nums = new ArrayList<>();
        nums.add(new Student(21, "kalyan"));
        nums.add(new Student(20, "gungun"));
        nums.add(new Student(22, "harneet"));
        nums.add(new Student(23, "Roma"));
        Collections.sort(nums, comp);

        for(Student s:nums)
            System.out.println(s);  //printing object returns toString() method in java so we can override in class to do something else.
    }
}


💡we can also sort without passing comp method in sort() fun by extending comparable class -------
class Student implements Comparable<Student> {
     
     //banki ka code from above
    @Override
    public int compareTo(Student that) {
        if(this.age>that.age)
            return 1;
        else 
            return -1;
    }
}

sort(nums);  //dont need to pass comparator

-------lets make if else short

Comparator<Student>comp = new Comparator<Student>() {
            public int compare(Student i, Student j) {
                if(i.age>j.age)
                    return 1;
                else 
                return -1;
            }
        };
👇🏻
Comparator<Student>comp = new Comparator<Student>() {
            public int compare(Student i, Student j) {
                return i.age>j.age?1:-1;
            }
        };
👇🏻
Comparator<Student>comp = new Comparator<Student>() {
            public int compare(Student i, Student j) {
                return i.age>j.age?1:-1;
            }
        };

👇🏻😱
Comparator<Student>comp=(Student i, Student j)->i.age>j.age?1:-1;
👇🏻😱
Comparator<Student>comp=(i,  j)->i.age>j.age?1:-1;


 