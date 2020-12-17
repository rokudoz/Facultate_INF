package com.company;

public class Main {

    static void print(String s) {
        System.out.println(s);
    }

    public static void main(String[] args) {

        User user = new User("Robert", 23);

        user.printPublic();
        user.printProtected();
        user.printDefaultInterface();

        Human human = new Human();
        human.printPublic();
        human.printProtected();
        human.printDefaultInterface();
        human.printPublicInterface();

//        if (args == null || args.length == 0) {
//            print("0 argumente");
//        } else {
//            if (args.length < 2) {
//                print("1 argument " + args[0]);
//            } else {
//                print("mai multe argumente");
//                for (String s : args) {
//                    print(s);
//                }
//            }
//        }
    }
}
