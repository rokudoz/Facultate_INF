package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    static void print(String s) {
        System.out.println(s);
    }

    public static void main(String[] args) {
        Disc disc = new Disc("Disc", 256);
        SSD ssd = new SSD("SSD", 512, true);
        HDD hdd = new HDD("HDD", 1024, "SCSI");

        print(disc.toString());
        print(ssd.toString());
        print(hdd.toString());

    }
}

class Disc {
    String nume;
    Integer capacitate;

    public Disc(String nume, Integer capacitate) {
        this.nume = nume;
        this.capacitate = capacitate;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public Integer getCapacitate() {
        return capacitate;
    }

    public void setCapacitate(Integer capacitate) {
        this.capacitate = capacitate;
    }

    @Override
    public String toString() {
        return "Disc{" +
                "nume='" + nume + '\'' +
                ", capacitate=" + capacitate +
                '}';
    }
}

class SSD extends Disc {

    boolean stare;

    public SSD(String nume, Integer capacitate, Boolean stare) {
        super(nume, capacitate);
        this.stare = stare;
    }

    public boolean isStare() {
        return stare;
    }

    public void setStare(boolean stare) {
        this.stare = stare;
    }

    @Override
    public String toString() {
        return "SSD{" +
                "nume='" + nume + '\'' +
                ", capacitate=" + capacitate +
                ", stare=" + stare +
                '}';
    }
}

class HDD extends Disc {
    String controller;

    public HDD(String nume, Integer capacitate, String controller) {
        super(nume, capacitate);
        this.controller = controller;
    }

    @Override
    public String toString() {
        return "HDD{" +
                "nume='" + nume + '\'' +
                ", capacitate=" + capacitate +
                ", controller='" + controller + '\'' +
                '}';
    }
}