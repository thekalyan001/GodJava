package com.mishra.kalyan;

import static org.junit.Assert.*;

import org.junit.Test;
  
public class CalcTestJunit4 {


	@Test  //for calculating performance of unit we can also mention here @Test(timeout = 100)
	public void test() {
		Calc obj = new Calc();
		int actual = obj.add(10, 10);
		int expectedResult = 20;
		assertEquals(expectedResult, actual);
	}

}
