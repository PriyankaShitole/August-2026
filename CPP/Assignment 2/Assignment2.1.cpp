#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Product {

    int productID;
    string name;
    double price;
    int quantity;

public:

    void acceptDetails() {
        cin >> productID >> name >> price >> quantity;
    }

    void displayDetails(bool lowStock = false) const {

        cout << left
             << setw(8) << productID
             << setw(15) << name
             << setw(12) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue();

        if (lowStock) {
            cout << " <- LOW STOCK";
        }

        cout << endl;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

    string getName() const {
        return name;
    }

}; // Product class इथे संपली


// ================= PART B =================

// Function Overloading

double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate) {
    double cost = qty * unitPrice;
    return cost + (cost * taxRate / 100);
}


// Default Argument Function

double applyDiscount(double price, double discountPercent = 10.0) {
    return price - (price * discountPercent / 100);
}


// ================= MAIN =================

int main() {

    Product arr[5];

    cout << "Enter details of 5 products:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Product " << i + 1 << ": ";
        arr[i].acceptDetails();
    }


    int threshold;

    cout << "Enter threshold: ";
    cin >> threshold;


    cout << endl;
    cout << "===== INVENTORY REPORT =====" << endl;

    cout << left
         << setw(8) << "ID"
         << setw(15) << "Name"
         << setw(12) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value"
         << endl;

    cout << "----------------------------------------------------------"
         << endl;


    // Display all products

    for (int i = 0; i < 5; i++) {
        arr[i].displayDetails(arr[i].isLowStock(threshold));
    }


    // Find highest total value

    double highestValue = arr[0].totalValue();
    int highestIndex = 0;

    for (int i = 1; i < 5; i++) {

        if (arr[i].totalValue() > highestValue) {
            highestValue = arr[i].totalValue();
            highestIndex = i;
        }

    }


    cout << endl;

    cout << "Highest Value Product : "
         << arr[highestIndex].getName()
         << " (Rs. "
         << fixed << setprecision(2)
         << highestValue
         << ")" << endl;


    // Low stock products

    cout << "Low Stock (threshold: " << threshold << ") : ";

    bool found = false;

    for (int i = 0; i < 5; i++) {

        if (arr[i].isLowStock(threshold)) {

            if (found) {
                cout << ", ";
            }

            cout << arr[i].getName();
            found = true;
        }

    }

    if (!found) {
        cout << "None";
    }

    cout << endl;


    // PART B function calls

    cout << endl;

    cout << "Reorder Cost 1: "
         << reorderCost(5, 100.0) << endl;

    cout << "Reorder Cost 2: "
         << reorderCost(5.5, 100.0) << endl;

    cout << "Reorder Cost 3: "
         << reorderCost(5, 100.0, 18.0) << endl;

    cout << "Discount with default 10%: "
         << applyDiscount(1000) << endl;

    cout << "Discount with 20%: "
         << applyDiscount(1000, 20.0) << endl;


    return 0;
}
