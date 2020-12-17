package plafar;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import plafar.Models.Plant;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.Scanner;

public class HomeScreen implements Initializable, PlantListRow.OnButtonEventInterface {

    @FXML
    StackPane StackPane;

    private final ObservableList<Plant> plantList = FXCollections.observableArrayList();
    ListView<Plant> plantaListView = new ListView<>();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        readFromFile();
        initListView();
    }


    public void openLogin(ActionEvent event) throws IOException {
        Parent tableViewParent = FXMLLoader.load(getClass().getResource("login.fxml"));
        Scene tableViewScene = new Scene(tableViewParent);

        //This line gets the Stage information
        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

        window.setScene(tableViewScene);
        window.show();
    }

    private void readFromFile() {
        try {
            File myObj = new File("test.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                System.out.println(data);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }


    private void initListView() {
        StackPane.getChildren().add(plantaListView);

        plantList.addAll(
                new Plant("Planta 1", 1, 0.0),
                new Plant("Planta 2", 2, 0.0),
                new Plant("Planta 3", 3, 0.0),
                new Plant("Planta 4", 4, 0.0),
                new Plant("Planta 5", 5, 0.0)
        );

        plantaListView.setCellFactory(c -> new PlantListRow(this));
        plantaListView.setItems(plantList);
    }


    @Override
    public void onAddButton(Plant planta) {
        planta.setQuantity(planta.getQuantity() + 1);
        plantList.get(plantList.indexOf(planta)).setQuantity(planta.getQuantity());
        plantaListView.getItems().set(plantList.indexOf(planta), planta);
    }

    @Override
    public void onSubButton(Plant planta) {
        if (planta.getQuantity() > 0) {
            planta.setQuantity(planta.getQuantity() - 1);
            plantList.get(plantList.indexOf(planta)).setQuantity(planta.getQuantity());
            plantaListView.getItems().set(plantList.indexOf(planta), planta);
        }
    }

}
