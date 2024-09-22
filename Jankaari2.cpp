💡Remember: Things are not diffculy, its just unfamiliar.
https://interviewprep.org/publicis-sapient-interview-questions/


-----12:00:00-Stream Api 🌊 🎏.
 Stream has multiple values, map, filter, reduce and multple methods


List<Integer> nums = Arrays.asList(4, 5, 7, 3, 2, 6);
//before 
for(int i=0;i<nums.size();i++){
    system.out.println(nums.get(i));
}
for(int n:nums){
    system.out.println(n);
}


//after ✔
nums.forEach((n) -> {  // bhai ye to JS hai 🤡
    System.out.println(n);
});

or nums.forEach(n-> system.out.println(n)); 






-


💡Extra knowledge -> Internal implementation of For each---------
ForEach uses the Consumer which is functional interface (ctrl+click) and it has method accept() and we pass that into ForEach method. 

        Consumer<Integer> con = new Consumer<Integer>() {
            
            public void accept(Integer n){
                System.out.println(n);
            }
        };
        nums.forEach(con);

       👇🏻 can be written (in short)
               Consumer<Integer> con = (Integer n)->{
                System.out.println(n);
            };
        👇🏻 can be written (in short)
            Consumer<Integer> con = (n)->  System.out.println(n);

        👇🏻 can be written (in short)🤡
            Dont pass con just write (n)->  System.out.println(n) directly nito ForEach
            forEach(n-> system.out.println(n)); 



Internal implementation of For Filter---------
Filter uses Predicate which is functional interface (ctrl+click) and this Predicate has a bool method called test.
        
        Predicate<Integer> pr = new Predicate<Integer>() {
            @Override
            public boolean test(Integer n) {
                return n % 2 == 0;
            }
        };
       nums.stream().filter(pr);

    👇🏻 reduce code
        Predicate<Integer> pr = (n)-> {
            return n % 2 == 0;
        };
        nums.stream().filter(pr);

    👇🏻reduce code
         Predicate<Integer> pr = n-> n % 2 == 0;
         nums.stream().filter(pr);

    👇🏻reduce code 🤡
        nums.stream().filter(n-> n % 2 == 0);



Internal implementation of For Map---------
Map uses Function interface whch is a Functional interface (ctrl+click) and this has method called apply.

    Function<Integer, Integer> fun = new Function<Integer, Integer>() {
        public Integer apply(Integer n) {
            return n*2;
        }
    };
    nums.stream().map(fun)

    👇🏻reduced
    Function<Integer, Integer> fun = (n) ->  n*2;
    nums.stream().map(fun)

    👇🏻reduced🤡
    nums.stream().map(n->n*2)
-------------------------------------------------------------


lets see a program---use map, filter, reduce---

import java.util.Arrays;
import java.util.List; 

public class Demo {   
    public static void main(String[] args) {
        List<Integer> nums = Arrays.asList(4, 5, 7, 3, 2, 6);

        //apply filter-  get only odd values  and after that double that value and reduce that like sum
        int sum = 0;
        for (int n : nums)
        {
            if (n % 2 == 0) {  //filter
                n = n * 2;  //double value
                sum = sum + n; // sum, which is reduce
            }        
        }

        System.out.println(nums);
    }
}


--Stream 👩🏻🧵🏃🏻‍♂️✔🤡🎏
stream as name says-  it can only be used once.

List<Integer> nums = Arrays.asList(4, 5, 7, 3, 2, 6);
Stream<Integer>s1 = nums.stream();
s1.ForEach(n - > system.out.println(n)); 
s1.ForEach(n - > system.out.println(n));  // Error, s1 already used.

Benefit-> It give us multiple method-> Filter,  map, reduce.

List<Integer> nums = Arrays.asList(4, 5, 7, 3, 2, 6);
Stream<Integer>s1 = nums.stream();
Stream<Integer>s2 = s1.filter(n -> n%2==0);
Stream<Integer>s3 = s2.map(n -> n*2);

int result = s3.reduce(0, (c, e)-> c+e);
system.out.println(result);

in short-> 
int result = nums.stream()
                .filter(n -> n%2==0)
                .map(n -> n*2)
                .reduce(0, (c, e)-> c+e);


-------------------------12:30:00 Other methods, sort, filter, in Stream
public static void main(String[] args) {
        List<Integer> nums = Arrays.asList(4, 5, 7, 3, 2, 6);

        Stream<Integer> sortedValues = nums.stream()
                        .filter(n->n%2==0)
                        .sorted();
        sortedValues.forEach(n -> System.out.println(n));
       
    }

------------Use multiple threads for stream
we use parallelStream,  in sorting its not good to use this as we have to check all elemnts
but yes for filter we can use parallelStream

Stream<Integer> sortedValues = nums.parallelStream()
                        .filter(n->n%2==0)
                        .sorted();
sortedValues.forEach(n -> System.out.println("Value: " + n + ", Thread: " + Thread.currentThread().getName());





-----12:38:00--------LVTI  Local varable type inference  >jdk v-10
(Remember local varialbe not instance varialbe means not a class varialbe as instance variable means storage and local varialbe used for fun execution)

using local varialbe without data type

int vari = 10;
👇🏻 
var vari =10;

var a; //❌error must assign value to var

ArrayList obj = new ArrayList();
👇🏻 
var obj = new ArrayList();


class abc{
    var num=10; //❌ instance variale cant have var
}


int nums[] = new int[10];
👇🏻
var nums = new int[10]; // dont use [] sq bracket here.


Aliean obj = new Aliean();
👇🏻
var obj = new Aliean();


-------------------------12:47:00-----SEALED classes
Abstract vs final class
Abstract- base class and some defined methods, its ment to be inherited.
final - no class can inherit. its final class.

SEALED class- which subclass can inherit base class.
💡 Rule1. Subclass must extend this sealed class and it should be either final, sealed or non-sealed

usecase:- in payment we can allow this, that is allowed.  Laptop, mobile, Desktop can extend Computer

sealed class A permits B, C{  //allow which class can extend
}

non-sealed class B extends A {  //non sealed class can be extended 
}

final class C extends A { //can't be extended
}

class D extends B {
}

------in case of interface (we've two option for child class to have either sealed or non-sealed as interface cant be final)
sealed interface X permits Y{
}
sealed interface Y extends X {
} 





---------------------12:57:00---------RECORDED classes 📷

classes which id used for storage data purposes. like calling to db and getting obj and storing json format.
and the varialbe hold data we call as STATE.



See below class and then we'll convert this to Record class 🔥

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

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + id;
        result = prime * result + ((name == null) ? 0 : name.hashCode());
        return result;
    }

    // equal method behaviour change to check if value same then ob is same.
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Alien alien = (Alien) obj;
        return id == alien.id && Objects.equals(name, alien.name);
    }

    // this is when we print objects when obj print then do this.
    @Override
    public String toString() {
        return "Alien [id=" + id + ", name=" + name + "]";
    }
    
    
    
    
} 

public class Demo {
    public static void main(String[] args) {
        Alien ob1 = new Alien(1, "Zorg");
        Alien ob2 = new Alien(1, "Zorg");

        System.out.println(ob1.getName());
        System.out.println(ob1);
        System.out.println(ob1.equals(ob2));
    }
}


So just to hold data we're creating so many methods see above class. 😏
so we'll do all of this in single  line 🤐, yes in single line

in RECORDED class by dafault varialbes are final. 
--There is no setter n record class as its read only to store data.
--to read varialbes we can call ob.variable()

record Alien(int id, String name) {}  🤡 //every avobe methods are implemented here behind the scene.
 

public class Demo {
    public static void main(String[] args) {
        Alien ob1 = new Alien(1, "Zorg");
        Alien ob2 = new Alien(1, "Zorg");
        
        System.out.println(ob1.equals(ob2));
        System.out.println(ob1.name());
        System.out.println(ob1);
    }
}

---cannonical construtor- which have same name as class which have same number of fields as class.
it is automatically genered by compiler, but we can also write in order to do some checks within construtor.

eg;- 
record Alien(int id, String name) {
    if(id==0)
        throw new IllegalArgumentException("id cant be zero");
    // this.id=id
    // this.name=name  these things are by default in this this consturctor
}



------------UNIT TESTING  (JUNIT 5)-- 13:13:00
while developing software doing unit testing.

