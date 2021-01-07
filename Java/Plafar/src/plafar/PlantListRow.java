package plafar;

import javafx.geometry.Pos;
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
    private final Label priceLabel = new Label();
    private final Button buyBtn = new Button("Cumparare");

    public interface OnButtonEventInterface {
        void onBuyButton(Plant planta);
    }

    public PlantListRow(OnButtonEventInterface onButtonEventInterface) {
        this.onButtonEventInterface = onButtonEventInterface;

        descriptionLabel.setMaxWidth(250);
        descriptionLabel.setPrefWidth(250);
        quantityLabel.setMaxWidth(110);
        quantityLabel.setPrefWidth(110);
        priceLabel.setMaxWidth(110);
        priceLabel.setPrefWidth(110);

        content.setAlignment(Pos.CENTER_LEFT);
        content.getChildren().addAll(descriptionLabel, quantityLabel, priceLabel, buyBtn);
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
            priceLabel.setText(item.getPrice().toString());

            //Disable - Button if quantity <= 0
            buyBtn.setDisable(item.getQuantity() <= 0);

            buyBtn.setOnAction(e -> {

                onButtonEventInterface.onBuyButton(item);

                if (item.getQuantity() < 1)
                    buyBtn.setDisable(true);
            });
        }
    }

}
