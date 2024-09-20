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


------------------------------