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
import javafx.scene.control.MenuBar;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import plafar.Models.Plant;
import plafar.Utils.Dialogs;
import plafar.Utils.FileOps;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.Scanner;

public class HomeScreen implements Initializable, PlantListRow.OnButtonEventInterface {

    @FXML
    MenuBar menuBar;
    @FXML
    StackPane StackPane;

    private ObservableList<Plant> plantList = FXCollections.observableArrayList();
    ListView<Plant> plantListView = new ListView<>();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        plantList = FileOps.getPlantList();
        initListView();
    }


    private void initListView() {
        StackPane.getChildren().add(plantListView);

        plantListView.setCellFactory(c -> new PlantListRow(this));
        plantListView.setItems(plantList);
    }

    @Override
    public void onBuyButton(Plant planta) {

        if (planta.getQuantity() > 0) {
            Integer quantitySold = Dialogs.showQuantityDialog(planta);
            if (quantitySold <= 0)
                return;

            planta.setQuantity(planta.getQuantity() - quantitySold);
            plantList.get(plantList.indexOf(planta)).setQuantity(planta.getQuantity());
            plantListView.getItems().set(plantList.indexOf(planta), planta);

            FileOps.updateQuantity(planta, plantList.indexOf(planta));
            FileOps.addToSoldPlantsFile(planta, quantitySold);
        }
    }

    public void onAboutBtnClick() {
        Dialogs.showAboutMeDialog();
    }

    public void onAddPlantClick() {
        Plant plant = Dialogs.showAddNewPlantDialog();
        if (plant == null)
            return;

        plantList.add(plant);
        FileOps.addToPlantListFile(plant);
    }

    public void onLogOutClick() throws IOException {
        Parent tableViewParent = FXMLLoader.load(getClass().getResource("login.fxml"));
        Scene tableViewScene = new Scene(tableViewParent);

        //This line gets the Stage information
        Stage stage = (Stage) menuBar.getScene().getWindow();

        stage.setScene(tableViewScene);
        stage.show();
    }

}
