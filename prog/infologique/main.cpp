#include <iostream>
#include <string>
using namespace std;

const string BASE_DONNEES = "./base.txt"; 


class Product {
    private:
        int SKU = 696969;
        string brand = "BRAND_placeholder";
        string model = "MODEL_placeholder";
        float price = 696969.00;
    public:

    Product(int skuInput, string brandInput, string modelInput, float priceInput) {
        SKU = skuInput;
        brand = brandInput;
        model = modelInput;
        price = priceInput; 
    }

    int getSKU() {
        return SKU;
    }
    string getBrand() {
        return brand;
    }
    string getModel() {
        return model;
    }
    float getPrice() {
        return price;
    }
    string toString() {
        return to_string(SKU);
    }
};

class ProductList {
    private:
        struct Node {
            Product data;
            Node* next = nullptr;
        };
        *head = &Node
        
    public:

};


int main() {
    Product p;

    cout << p.toString();
    return 0;
}