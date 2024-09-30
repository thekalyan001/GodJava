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

Manual unit testing-
1. Prepare (setup test environment and wrte test method)
2. provide testing input
3. Run test
4. Provided expeceted output
5. perform assertion (verfy the result)
6. Report test result (alert developer if test failed/passes).

eg- call function of a class and check if the output from f/n on given input is correct.

JUNit 5 steps
1. Provided testng input 
2. Give expected output
3. Report test result to developer.

JUNIT5  architecture-
Junit doesnt have backward compatiblity like java 8= java7+new feature, but junit5 is != junit4+new
(we'll use jupiter api to write test) (we use vintage api to reuse the existing test cases like of Junit 4)


--------Create maven project & write junit test cases-
Ctrl+Shift+P

Create maven project- latest version->Java->com.mishra ->kalyan ->jar->21

Group id: com.mishra
Artifact id: kalyan
version- 0.0.1=3.2.1
package: jar


<!-- add junit library here. -->
	<dependency>
  		<groupId>junit</groupId>
  		<artifactId>junit</artifactId>
  		<version>4.13.2</version>
	</dependency>


my-app/
├── pom.xml
└── src/
    └── main/
        └── java/
            └── com/
                └── mishra/
                    └── kalyan/
                        └── Calc.java 
    └── test/
        └── java/
            └── com/
                └── mishra/
                    └── kalyan/ 
                        └── CalcTest.java 

src->main->com.mishra.kalyan->Calc.java 
package com.mishra.kalyan;
  
public class Calc {

	public int add(int a, int b) {
		return a + b;
	}

    public static void main(String[] args) {
        Calc ob = new Calc();
        System.out.println(ob.add(10,10));
	}

}


src->test->com.mishra.kalyan->CalcTestJunit4.java
package com.mishra.kalyan;

import static org.junit.Assert.*;

import org.junit.Test;
  
public class CalcTest {


	@Test
	public void test_add() {
		Calc obj = new Calc();
		int actual = obj.add(10, 10);
		int expectedResult = 20;
		assertEquals(expectedResult, actual);
	}

}


click beaker test to run it.
🎉wooah.


-14:00:00  JUNit 5 Jupiter test write--------------
CalcTestJupiterJunit5.java


package com.mishra.kalyan;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;  //junit 5 test assertion

public class CalcTestJupiterJunit5 {
    

    @Test
    void test_add() {
        Calc ob = new Calc();
        int actual = ob.add(10, 20);
        int expected = 30;
        assertEquals(expected, actual);
    }
}


-----Annotation of junit Test file----
in junit4 @Test method should be public and class also.
in Junit5 @Test method is by default is default, and it can be public, private, protected


import org.junit.Test; //junit4
import org.junit.jupiter.api.Test;  // Junit5

assertEquals ->comparison between expectation and actual.
many other are there-> assertArrayEquals, assertEquals, assertNotEquals, assertTrue, assertFalse, assertNull, assertNotNull 

-------------14:46:00
We'll have to install SureFire plugin in order to run test on ci/cd pileline as they will not right click and run the project.
https://maven.apache.org/surefire/maven-surefire-plugin/

        <plugin>
            <groupId>org.apache.maven.plugins</groupId>
            <artifactId>maven-surefire-plugin</artifactId>
            <version>3.5.0</version>
        </plugin>

Here we are passing string as supplier interface-> so it will only get executed once test is failed.
but if we pass string then everythime it would get evaluated is test is passed/failed no matter.
so we can say supplier wala will do lazy evaluation.

    //direct message string
    assertEquals(expected, actual, "Value is not equal");

    // GIVING MSG AS SUPPLIER FUNCTIONAL INTERFACE
    assertEquals(expected, actual, ()->"Value is not equal");
    
------assertNotEquals (if expectation is not matching with reality then Test will pass else fail  (opposite of assertEquals))
------assertTrue(true);  this will pass the test case.  eg- assertTrue(givenStrng.equals("Junit"));



----------15:37:00-  Performance of a unit- (if test is longer running task)
for junit4 we can directly mention within what time it should execute. @Test(timeout = 100)

and for junit5 we should-> assertTimeout
  @Test
    public void testPerformanceOfUnit() {
        Calc ob = new Calc();
        int unsorted[] = { 2, 5, 1 };
        assertTimeout(Duration.ofMillis(10), () -> ob.sortingArray(unsorted));
    }

---------Lifecycle of java classes
starting initialiation block ->then static method invoke using class ->then object/instance creation (consturctor block)-> then function invoke using instance ->then obj is destroid
--------Lifecycle of java test case
craete instance ->invoke BeforeEach annotation ->invoke destroy test after every test case.

we use before each to initialise the obj before each @Test method
eg- db connection, file open, network connection etc something which is common between every @TEst function we write it in init.

-------------@BeforeEach (before each test case it will get called)
public void init() {
    Demo obj = new Demo();
    System.out.println("init called");
}

-------------@AfterEach(after each test case it will get called)
void destroy(){
    // clean up code here
    System.out.println("destroy called");
}

-------------BeforeAll (independent of test case it will called only once before all test case, even before instance of class creation also)

    @BeforeAll
    static void beforeAll() {
        System.out.println("Before All");
    }

------------AfterAll (vice versa- after all it will execute only once.)
eg:- close common resource.

    @AfterAll
    static void AfterAll() {
        System.out.println("Before All");
    }


-----------15:20:00------------Changinng behaviour of instance

💡Note- for every @Test different class instance gets created.
so if you want to cerate only once and we can run @BeforeAll and @AfterAll without static

@TestInstance (TestInstance.Lifecycle.PER_CLASS)
class TestWalaClass {
    @BeforeEach
    void init() {
        Demo obj = new Demo();
        System.out.println("init called");
    }

    @AfterAll
    static void AfterAll() {
        System.out.println("Before All");
    }
}



-----------------16:05:00---------------DATA STRUCTURES 🌊🏃🏻‍♂️--------------------------
Organise data efficiantly and in min time utilise it.

--Time completixty:- 
Set of steps to solve a problem called algorithm
Big-O ->
O(1) - Constant time
O(logn) - Logarithmic time
O(n) - Linear time
O(nlogn) - Loglinear time
O(n^2) - Quadratic time
O(2^n) - Exponential time
O(n!) - Factorial time


Sorting--
1. Bubble sort- if found bigger value than previous then swap
2. selection sort - bring smaller value at first from left. (17:33:00)
3. insertion sort - bring smaller value at right
4. quick sort - divide array into 2 parts and sort them (17:58:00)
5. merge sort - divide array into 2 parts and sort them

quick sort-  nlogn
private static int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low-1);
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], high); 
    return i+1;
}
public static void quicksort(arr, low, high){
    if(low<high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

mergesort-
merge(int[] arr, low, mid, high){ 
    int n1 = mid-low+1, n2 = high-mid;
    int left[] = new int[n1], right[] = new int[n2];
    
    for(int i=0;i<n1;i++){
        left[i] = arr[low+i];
    }
    for(int j=0;j<n2;j++){
        right[j] = arr[mid+1+j];
    }
    int i=0, j=0, k=low;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}
mergeSort(arr, low, high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}


------------LInked list  18:56:00
Every node is an object which will have address of other object.
public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.add(10);
        list.add(20);
        list.add(30);
        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }

check DataStructures -> LinkList.java


---------Stack 19:50:00 
by default collection stack size is 10, and if we push then it got increased by 1.
import java.util.Stack;
public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 1; i <= 12; i++) {
            stack.push(i);
        }
        System.out.println(stack.capacity());
        System.out.println(stack.peek());
    }

check DataStructures -> StackCode.java

----------Queue20:26:00

import java.util.LinkedList;
import java.util.Queue;
public static void main(String[] args) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(10);
    queue.add(20);
    System.out.println("Front element is: " + queue.peek());
    System.out.println("Removed element: " + queue.remove());
    System.out.println("Queue after removal: " + queue);
    System.out.println("Is the queue empty? " + queue.isEmpty());      
}

------------Tree 🌲 20:49:00



1. Strict B.T -   must have 2 or no child
2. Full B.T- Every subnode have 2 node and all leaf node at same level
3. Complete B.T - if we represent it in array then there should not be gap.


BST - Left side lower than root, right side larger than root.