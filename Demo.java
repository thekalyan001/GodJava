 
import java.util.Arrays;
import java.util.List; 

public class Demo {   
    public static void main(String[] args) {
        List<Integer> nums = Arrays.asList(4, 5, 7, 3, 2, 6);

        nums.forEach((n) -> {
            System.out.println(n);
        });
        //apply filter-  get only odd values  and after that double that value and reduce that like sum
        // int sum = 0;
        // for (int n : nums)
        // {
        //     if (n % 2 == 0) {  //filter
        //         n = n * 2;  //double value
        //         sum = sum + n; // sum, which is reduce
        //     }        
        // }

        // System.out.println(nums);
    }
}
