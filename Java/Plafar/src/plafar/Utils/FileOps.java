package plafar.Utils;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import plafar.Models.Plant;
import plafar.Models.User;

import java.io.*;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class FileOps {

    public static ObservableList<Plant> getPlantList() {
        ObservableList<Plant> plantList = FXCollections.observableArrayList();

        try {
            File myObj = new File("Lista_Plante.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                String[] plantDetails = data.split(" ;");

                plantList.add(new Plant(plantDetails[0], Integer.parseInt(plantDetails[1]), Double.parseDouble(plantDetails[2])));
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        return plantList;
    }

    public static List<User> getUserList() throws IOException {
        List<User> userList = new ArrayList<>();

        try {
            File myObj = new File("login_info.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                String[] userDetails = data.split(";");
                userList.add(new User(userDetails[0], userDetails[1]));
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();

            //Login file did not exist, create one with dummy account
            FileOutputStream fileOut = new FileOutputStream("login_info.txt");
            String dummyAccount = "admin;admin";
            fileOut.write(dummyAccount.getBytes());
            fileOut.close();
            userList = getUserList();

            System.out.println("Fisierul login_info.txt nu a fost gasit, a fost creat in schimb unul cu un cont prestabilit");
        }

        return userList;
    }

    public static void updateQuantity(Plant plant, Integer position) {
        try {
            BufferedReader file = new BufferedReader(new FileReader("Lista_Plante.txt"));
            StringBuffer inputBuffer = new StringBuffer();
            String line;
            int index = 0;

            while ((line = file.readLine()) != null) {
                if (index == position) {
                    String substitute = plant.getName() + " ;" + plant.getQuantity() + " ;" + plant.getPrice();
                    inputBuffer.append(substitute);
                } else {
                    inputBuffer.append(line);

                }
                inputBuffer.append('\n');
                index++;
            }
            file.close();

            // write to the plant list file
            FileOutputStream fileOut = new FileOutputStream("Lista_Plante.txt");
            fileOut.write(inputBuffer.toString().getBytes());
            fileOut.close();

        } catch (Exception e) {
            System.out.println("An error occurred");
            e.printStackTrace();
        }
    }

    public static void addToSoldPlantsFile(Plant plant, int quantitySold) {
        String toAppend = Date.from(Instant.now()) + " || " + plant.getName() + " ;" + quantitySold + "" + "\n";
        appendToFile(toAppend, "PlanteVandute.txt");
    }

    public static void addToPlantListFile(Plant plant) {
        String plantToAdd = plant.getName() + " ;" + plant.getQuantity() + " ;" + plant.getPrice();
        appendToFile(plantToAdd, "Lista_Plante.txt");
    }

    private static void appendToFile(String string, String fileName) {
        try {
            Writer output;
            output = new BufferedWriter(new FileWriter(fileName, true));

            output.append(string);

            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
