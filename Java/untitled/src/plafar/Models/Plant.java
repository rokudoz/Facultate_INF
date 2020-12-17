package plafar.Models;

import java.util.Objects;

public class Plant {
    private String name;
    private Integer quantity;
    private Double price;

    public Plant(String denumire, Integer cantitate, Double pret) {
        this.name = denumire;
        this.quantity = cantitate;
        this.price = pret;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getQuantity() {
        return quantity;
    }

    public void setQuantity(Integer quantity) {
        this.quantity = quantity;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Plant planta = (Plant) o;
        return name.equals(planta.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}
