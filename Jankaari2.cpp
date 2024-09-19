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
nums.forEach((n) -> {  //stream api - bhai ye to JS hai 🤡
    System.out.println(n);
});

or nums.forEach(n-> system.out.println(n)); 



Before that lets see a program------

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


