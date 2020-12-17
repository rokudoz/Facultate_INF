package plafar;

import javafx.scene.control.Button;
import javafx.scene.control.ContentDisplay;
import javafx.scene.control.Label;
import javafx.scene.control.ListCell;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import plafar.Models.Plant;

public class PlantListRow extends ListCell<Plant> {

    private OnButtonEventInterface onButtonEventInterface = null;

    private final HBox content = new HBox();
    private final Label descriptionLabel = new Label();
    private final Label quantityLabel = new Label();
    private final Button add = new Button("+");
    private final Button sub = new Button("-");

    public interface OnButtonEventInterface {
        void onAddButton(Plant planta);

        void onSubButton(Plant planta);
    }

    public PlantListRow(OnButtonEventInterface onButtonEventInterface) {
        this.onButtonEventInterface = onButtonEventInterface;

        descriptionLabel.setMaxWidth(Double.MAX_VALUE);
        quantityLabel.setMaxWidth(Double.MAX_VALUE);
        HBox.setHgrow(descriptionLabel, Priority.ALWAYS);
        HBox.setHgrow(quantityLabel, Priority.ALWAYS);
        content.getChildren().addAll(descriptionLabel, quantityLabel, add, sub);
        content.setSpacing(10);
        setContentDisplay(ContentDisplay.GRAPHIC_ONLY);
        setGraphic(content);
    }

    @Override
    protected void updateItem(Plant item, boolean empty) {
        super.updateItem(item, empty);
        if (item == null || empty) {
            setText(null);
            setGraphic(null);
        } else {
            setGraphic(content);
            descriptionLabel.setText(item.getName());
            quantityLabel.setText(item.getQuantity().toString());

            //Disable - Button if quantity <= 0
            sub.setDisable(item.getQuantity() <= 0);

            add.setOnAction(e -> {
                //Enable - button again because quantity can't be < 0
                sub.setDisable(false);

                onButtonEventInterface.onAddButton(item);
            });

            sub.setOnAction(e -> {

                onButtonEventInterface.onSubButton(item);

                if (item.getQuantity() < 1)
                    sub.setDisable(true);
            });
        }
    }

}
