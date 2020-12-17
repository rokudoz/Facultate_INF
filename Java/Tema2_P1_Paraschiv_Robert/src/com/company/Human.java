package com.company;

public class Human implements interfaceTest {
    public Human() {
    }

    public void printPublic() {
        System.out.println("Public");
    }

    @Override
    public void printPublicInterface() {
        System.out.println("Public interface");

    }

    protected void printProtected() {
        System.out.println("Protected");
    }
}
