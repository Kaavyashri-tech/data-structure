
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> cars;
    int choice, car;

    do {
        cout << "\n1. Park a Car";
        cout << "\n2. Remove a Car";
        cout << "\n3. Display Parked Cars";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter car number: ";
                cin >> car;
                cars.push(car);
                cout << "Car parked successfully!\n";
                break;

            case 2:
                if (cars.empty()) {
                    cout << "Parking garage is empty!\n";
                } else {
                    cout << "Car " << cars.top()
                         << " left the garage.\n";
                    cars.pop();
                }
                break;

            case 3:
                if (cars.empty()) {
                    cout << "No cars parked!\n";
                } else {
                    stack<int> temp = cars;
                    cout << "Cars (last entered first): ";
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

