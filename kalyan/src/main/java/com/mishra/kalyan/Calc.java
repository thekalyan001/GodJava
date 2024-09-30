package com.mishra.kalyan;

import java.util.Arrays;

public class Calc {

	public int add(int a, int b) {
		return a + b;
	}

	public int[] sortingArray(int[] array) {
		for (int i = 0; i < 10000; i++) {
			Arrays.sort(array);
		}
		return array;
	}

    public static void main(String[] args) {
        Calc ob = new Calc();
        System.out.println(ob.add(10,10));
	}

}
