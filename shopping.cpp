#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> items;
    int choice;
    string item;

    do {
        cout << "\n--- Shopping List ---\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Search Item\n";
        cout << "4. Display All Items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                cin >> item;
                items.push_back(item);
                cout << "Item added successfully!\n";
                break;

            case 2: {
                cout << "Enter item to remove: ";
                cin >> item;

                bool found = false;
                for (int i = 0; i < items.size(); i++) {
                    if (items[i] == item) {
                        items.erase(items.begin() + i);
                        found = true;
                        break;
                    }
                }

                if (found)
                    cout << "Item removed successfully!\n";
                else
                    cout << "Item not found!\n";
                break;
            }

            case 3:
                cout << "Enter item to search: ";
                cin >> item;

                {
                    bool found = false;
                    for (int i = 0; i < items.size(); i++) {
                        if (items[i] == item) {
                            found = true;
                            break;
                        }
                    }

                    if (found)
                        cout << "Item found!\n";
                    else
                        cout << "Item not found!\n";
                }
                break;

            case 4:
                cout << "\nShopping List:\n";
                if (items.empty()) {
                    cout << "List is empty!\n";
                } else {
                    for (int i = 0; i < items.size(); i++) {
                        cout << i + 1 << ". " << items[i] << "\n";
                    }
                }
                break;

            case 5:
                cout << "Exiting Shopping List...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
