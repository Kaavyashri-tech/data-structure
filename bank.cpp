
#include <iostream>
using namespace std;

#define SIZE 10

int table[SIZE];

void insert(int x) {
    int index = x % SIZE;

    while (table[index] != -1) {
        index = (index + 1) % SIZE;
    }

    table[index] = x;
    cout << "Inserted successfully\n";
}

void search(int x) {
    int index = x % SIZE;
    int start = index;

    while (table[index] != -1) {
        if (table[index] == x) {
            cout << "Account found at index " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << "Account not found\n";
}

void display() {
    cout << "Hash Table:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }
}

int main() {
    int choice, x;

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    do {
        cout << "\n1. INSERT";
        cout << "\n2. SEARCH";
        cout << "\n3. DISPLAY";
        cout << "\n4. EXIT";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> x;
                insert(x);
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> x;
                search(x);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
