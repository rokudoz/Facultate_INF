package com.company;

public interface interfaceTest {

    default void printDefaultInterface(){
        System.out.println("Default interface");
    }

    void printPublicInterface();
}
