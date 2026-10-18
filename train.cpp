
#include <iostream>
using namespace std;

struct Node {
    int coach;
    Node* next;
};

Node* head = NULL;

void addBeginning(int n) {
    Node* newNode = new Node;
    newNode->coach = n;
    newNode->next = head;
    head = newNode;
}

void addEnd(int n) {
    Node* newNode = new Node;
    newNode->coach = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void removeCoach(int n) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->coach != n) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Coach not found!\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Coach removed successfully!\n";
}

void display() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "No coaches available!\n";
        return;
    }

    while (temp != NULL) {
        cout << "Coach" << temp->coach << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    int choice, n;

    do {
        cout << "\n1. Add at Beginning";
        cout << "\n2. Add at End";
        cout << "\n3. Remove Coach";
        cout << "\n4. Display Coaches";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                cin >> n;
                addBeginning(n);
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> n;
                addEnd(n);
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> n;
                removeCoach(n);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
