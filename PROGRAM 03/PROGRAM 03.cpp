



#include <iostream>

#include <string>

#include <vector>

using namespace std;


class Product {

private:

    int id;

    string name;

    double price;

public:

    Product(int productId, string productName, double productPrice)

        : id(productId), name(productName), price(productPrice) {}

    void display() const {

        cout << id << " | " << name << " | Rs. " << price << endl;

    }

};


int main() {

    vector<Product> products{

        Product(1, "Laptop", 65000),

        Product(2, "Phone", 30000),

        Product(3, "Headphones", 2500)

    };

    cout << "=== Product Catalog ===" << endl;

    for (const auto& product : products) {

        product.display();

    }

}

