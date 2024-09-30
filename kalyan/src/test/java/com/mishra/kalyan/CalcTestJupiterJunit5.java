package com.mishra.kalyan;

import static org.junit.jupiter.api.Assertions.*;

import java.time.Duration;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test; //junit 5 test assertion


class CalcTestJupiterJunit5 {
    
    @BeforeAll
    static void beforeAll() {
        System.out.println("Before All");
    }

    @Test
    void test_addFunction() {
        Calc ob = new Calc();
        int actual = ob.add(10, 20);
        int expected = 30;
        assertEquals(expected, actual, "Value is not equal");
    }

    // GIVING MSG AS SUPPLIER FUNCTIONAL INTERFACE
    @Test
    void test_addFunction_Supplier() {
        Calc ob = new Calc();
        int actual = ob.add(10, 20);
        int expected = 30;
        assertEquals(expected, actual, "Value is not equal");
        // assertEquals(expected, actual, () -> "Value is not equal");
    }
    
    @Test
    public void testPerformanceOfUnit() {
        Calc ob = new Calc();
        int unsorted[] = { 2, 5, 1 };
        assertTimeout(Duration.ofMillis(10), () -> ob.sortingArray(unsorted));
    }
}
