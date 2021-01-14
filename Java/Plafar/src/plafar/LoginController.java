package plafar;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;
import plafar.Models.Plant;
import plafar.Models.User;
import plafar.Utils.FileOps;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;
import java.util.Scanner;

public class LoginController implements Initializable {

    @FXML
    TextField username_field;
    @FXML
    PasswordField password_field;
    @FXML
    Button login_btn;

    List<User> userList = new ArrayList<>();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        try {
            userList = FileOps.getUserList();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void logIn(ActionEvent event) throws IOException {
        if (username_field.getText() != null && password_field.getText() != null) {
            User user = new User(username_field.getText(), password_field.getText());
            if (userList.contains(user)) {
                openHomeScreen(event);
            } else {
                Alert alert = new Alert(Alert.AlertType.ERROR, "Username sau parola introduse gresit", ButtonType.OK);
                alert.showAndWait();

                if (alert.getResult() == ButtonType.OK) {
                    alert.close();
                }
                System.out.println("User not registered");
            }
        }
    }


    private void openHomeScreen(ActionEvent event) throws IOException {
        Parent tableViewParent = FXMLLoader.load(getClass().getResource("home_screen.fxml"));
        Scene tableViewScene = new Scene(tableViewParent);

        //This line gets the Stage information
        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();

        window.setScene(tableViewScene);
        window.show();
    }

}
