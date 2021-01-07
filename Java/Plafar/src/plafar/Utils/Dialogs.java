package plafar.Utils;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;
import plafar.Models.Plant;

public class Dialogs {
    private static int quantity = 0;
    private static Double price = 0.0;
    private static Plant plantToAdd = null;

    public static Integer showQuantityDialog(Plant plant) {
        //Reseteaza variabilele pentru urmatorul apel
        quantity = 0;
        price = 0.0;

        Stage dialogStage = new Stage();

        dialogStage.setHeight(300);
        dialogStage.setWidth(500);
        dialogStage.initModality(Modality.APPLICATION_MODAL);
        dialogStage.resizableProperty().setValue(Boolean.FALSE);

        Button buyBtn = new Button("Cumpara");

        TextField quantityField = new TextField();

        quantityField.setMaxWidth(200);
        quantityField.setPromptText("Cantitate");

        Label priceLabel = new Label();

        VBox vbox = new VBox(new Text("Introduceti cantitatea dorita pentru " + plant.getName()), quantityField, priceLabel, buyBtn);

        vbox.setAlignment(Pos.CENTER);
        vbox.setPadding(new Insets(55));
        vbox.setSpacing(10);


        quantityField.textProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue.trim().equals("")) {
                priceLabel.setText("Campul pentru cantitate nu poate fi gol");
            } else {
                try {
                    int inputQuantity = Integer.parseInt(newValue);
                    if (plant.getQuantity() >= inputQuantity) {
                        price = plant.getPrice() * inputQuantity;
                        priceLabel.setText("Pret total: " + price);
                    } else {
                        priceLabel.setText("Ati selectat o cantitate mai mare decat cea disponibila");
                    }
                } catch (NumberFormatException numberFormatException) {
                    priceLabel.setText("Campul poate contine doar cifre");
                }
            }
        });

        buyBtn.setOnAction(actionEvent -> {
            if (quantityField.getText().trim().equals("")) {
                priceLabel.setText("Campul pentru cantitate nu poate fi gol");
            } else {
                try {
                    int inputQuantity = Integer.parseInt(quantityField.getText());

                    if (plant.getQuantity() >= inputQuantity) {
                        quantity = inputQuantity;
                        dialogStage.close();
                    } else {
                        priceLabel.setText("Ati selectat o cantitate mai mare decat cea disponibila");
                    }
                } catch (NumberFormatException numberFormatException) {
                    priceLabel.setText("Campul poate contine doar cifre");
                }

            }
        });

        dialogStage.setScene(new Scene(vbox));
        dialogStage.showAndWait();

        return quantity;
    }

    public static Plant showAddNewPlantDialog() {
        plantToAdd = null;

        Stage dialogStage = new Stage();

        dialogStage.setHeight(300);
        dialogStage.setWidth(500);
        dialogStage.initModality(Modality.APPLICATION_MODAL);
        dialogStage.resizableProperty().setValue(Boolean.FALSE);

        Button addBtn = new Button("Adauga");

        TextField nameField = new TextField();
        TextField quantityField = new TextField();
        TextField priceField = new TextField();

        nameField.setMaxWidth(200);
        nameField.setPromptText("Denumire");

        quantityField.setMaxWidth(200);
        quantityField.setPromptText("Cantitate");

        priceField.setMaxWidth(200);
        priceField.setPromptText("Pretul");

        VBox vbox = new VBox(new Text("Denumirea plantei"), nameField,
                new Text("Cantitatea diponibila"), quantityField,
                new Text("Pretul plantei"), priceField,
                addBtn);

        vbox.setAlignment(Pos.CENTER);
        vbox.setPadding(new Insets(55));
        vbox.setSpacing(10);

        addBtn.setOnAction(actionEvent -> {
            try {
                String plantName = nameField.getText();
                Integer plantQuantity = Integer.parseInt(quantityField.getText());
                Double plantPrice = Double.parseDouble(priceField.getText());

                plantToAdd = new Plant(plantName, plantQuantity, plantPrice);
                dialogStage.close();
            } catch (NumberFormatException numberFormatException) {
                Alert alert = new Alert(Alert.AlertType.WARNING, "Campurile pentru cantitate si pret pot contine doar cifre", ButtonType.OK);
                alert.showAndWait();

                if (alert.getResult() == ButtonType.OK) {
                    alert.close();
                }
                System.out.println(numberFormatException.getMessage());
            }
        });

        dialogStage.setScene(new Scene(vbox));
        dialogStage.showAndWait();

        return plantToAdd;
    }

    public static void showAboutMeDialog() {
        Stage dialogStage = new Stage();

        dialogStage.setHeight(300);
        dialogStage.setWidth(700);

        dialogStage.initModality(Modality.APPLICATION_MODAL);
        dialogStage.resizableProperty().setValue(Boolean.FALSE);

        Button okBtn = new Button("Ok");

        VBox vbox = new VBox(new Text("Acesta este un program destinat tinerii evidentei plantelor medicinale dintr-un magazin Plafar \n\nCreat de: \nParaschiv Longin-Robert"), okBtn);

        vbox.setAlignment(Pos.CENTER);
        vbox.setPadding(new Insets(55));
        vbox.setSpacing(10);

        okBtn.setOnAction(actionEvent -> {
            dialogStage.close();
        });

        dialogStage.setScene(new Scene(vbox));
        dialogStage.showAndWait();
    }
}
