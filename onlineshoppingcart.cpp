#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
    string name;
    double price;

    Item(string n, double p) {
        name = n;
        price = p;
    }

    void displayItem() const {
        cout << "Item: " << name << ", Price: $" << price << endl;
    }
};

class ShoppingCart {
private:
    vector<Item> cart;
    double totalPrice;

public:
    ShoppingCart() {
        totalPrice = 0.0;
    }

    void addItem(const Item& item) {
        cart.push_back(item);
        totalPrice += item.price;
    }

    void removeItem(const string& itemName) {
        for (auto it = cart.begin(); it != cart.end(); it++) {
            if (it->name == itemName) {
                totalPrice -= it->price;
                cart.erase(it);
                cout << itemName << " has been removed from your cart.\n";
                return;
            }
        }
        cout << "Item not found in the cart.\n";
    }

    void displayCart() const {
        if (cart.empty()) {
            cout << "Your cart is empty.\n";
            return;
        }

        cout << "\nItems in your cart:\n";
        for (const auto& item : cart) {
            item.displayItem();
        }
    }

    double getTotalPrice() const {
        return totalPrice;
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string itemName;
    double itemPrice;

    while (true) {
        cout << "\n===== Shopping Cart System =====\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                getline(cin, itemName);

                cout << "Enter item price: ";
                cin >> itemPrice;

                cart.addItem(Item(itemName, itemPrice));

                cout << itemName << " added successfully!\n";
                break;

            case 2:
                cout << "Enter item name to remove: ";
                getline(cin, itemName);

                cart.removeItem(itemName);
                break;

            case 3:
                cart.displayCart();
                break;

            case 4:
                cout << "\nTotal Price: $" << cart.getTotalPrice() << endl;
                break;

            case 5:
                cout << "Thank you for using the Shopping Cart System!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}