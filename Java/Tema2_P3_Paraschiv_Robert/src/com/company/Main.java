package com.company;

public class Main {

    static String f(String s) {
        return s + "<-->";
    }

    public static void main(String[] args) {
        // write your code here
        System.out.println(f("YEP"));

        if (args != null && args.length > 0) {
            System.out.println(f(args[0]));
        }
    }
}
