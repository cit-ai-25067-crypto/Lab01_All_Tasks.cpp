//Task 01: InventoryItem (Part 2: Item code = 3 letters + _ + running number)

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

const int MAX_ITEMS = 10;
int itemCount = 0;
int itemCounter = 31203;   // running integer, starts from 31203

struct InventoryItem {
    string itemCode;
    string itemName;
    double cost;
    double sellingPrice;
};

// Builds code like COM_31203 from the first 3 letters of the name
string generateItemCode(const string& name) {
    string prefix = name.substr(0, 3);
    for (char& c : prefix) {
        c = toupper(c);
    }
    return prefix + "_" + to_string(itemCounter++);
}

InventoryItem insertItem() {
    InventoryItem item;

    cout << "Enter item name: ";
    getline(cin, item.itemName);

    cout << "Enter cost: ";
    cin >> item.cost;
    cin.ignore(1000, '\n');

    item.sellingPrice = item.cost * 1.40;   // 40% profit
    item.itemCode = generateItemCode(item.itemName);
    return item;
}

void displayStock(const InventoryItem* items) {
    cout << "\n" << left
         << setw(12) << "Item Code"
         << setw(20) << "Item Name"
         << setw(12) << "Cost"
         << setw(15) << "Selling Price" << "\n";
    cout << string(59, '-') << "\n";

    for (int i = 0; i < itemCount; i++) {
        cout << left
             << setw(12) << items[i].itemCode
             << setw(20) << items[i].itemName
             << setw(12) << fixed << setprecision(2) << items[i].cost
             << setw(15) << items[i].sellingPrice << "\n";
    }
}

int main() {
    InventoryItem stock[MAX_ITEMS];

    cout << "How many items do you want to enter (max " << MAX_ITEMS << ")? ";
    cin >> itemCount;
    cin.ignore(1000, '\n');

    if (itemCount > MAX_ITEMS) itemCount = MAX_ITEMS;

    for (int i = 0; i < itemCount; i++) {
        cout << "\nItem " << i + 1 << ":\n";
        stock[i] = insertItem();
    }

    displayStock(stock);
    return 0;
}

//Task 02: Carpet Cost Calculator

#include <iostream>
using namespace std;

const double PRICE_PER_SQFT = 18.0;

struct FeetInches {
    int feet;
    int inches;
};

struct RoomDimension {
    FeetInches length;
    FeetInches width;
};

// Converts feet+inches to decimal feet
double toFeet(const FeetInches& f) {
    return f.feet + f.inches / 12.0;
}

// Returns the carpet cost for one room (area x price per sq ft)
int computeTheCarpetingCost(const RoomDimension& room) {
    double area = toFeet(room.length) * toFeet(room.width);
    return static_cast<int>(area * PRICE_PER_SQFT + 0.5);
}

void enterRoom(RoomDimension& room) {
    cout << "  Length - feet: ";
    cin >> room.length.feet;
    cout << "  Length - inches: ";
    cin >> room.length.inches;
    cout << "  Width - feet: ";
    cin >> room.width.feet;
    cout << "  Width - inches: ";
    cin >> room.width.inches;
}

int main() {
    int numRooms = 0;
    RoomDimension* rooms = nullptr;
    bool entered = false;
    int choice;

    do {
        cout << "\n===== Carpet Menu =====\n";
        cout << "1. Enter room dimensions\n";
        cout << "2. Show cost of each room\n";
        cout << "3. Show total cost of the house\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            if (rooms != nullptr) {
                delete[] rooms;
            }
            cout << "How many rooms in the house? ";
            cin >> numRooms;

            rooms = new RoomDimension[numRooms];
            for (int i = 0; i < numRooms; i++) {
                cout << "\nRoom " << i + 1 << ":\n";
                enterRoom(rooms[i]);
            }
            entered = true;
        }
        else if (choice == 2) {
            if (!entered) {
                cout << "Please enter the rooms first (option 1).\n";
                continue;
            }
            for (int i = 0; i < numRooms; i++) {
                cout << "Room " << i + 1 << " cost: Rs. "
                     << computeTheCarpetingCost(rooms[i]) << "\n";
            }
        }
        else if (choice == 3) {
            if (!entered) {
                cout << "Please enter the rooms first (option 1).\n";
                continue;
            }
            int total = 0;
            for (int i = 0; i < numRooms; i++) {
                total += computeTheCarpetingCost(rooms[i]);
            }
            cout << "Total carpet cost: Rs. " << total << "\n";
        }
        else if (choice != 0) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    delete[] rooms;
    return 0;
}
