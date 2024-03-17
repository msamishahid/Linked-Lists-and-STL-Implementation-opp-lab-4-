#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
                                        
    void append(int data) {          // Function to append a new node to the end of the linked list
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display() {              // Function to display the elements of the linked list
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    bool search(int key) {        // Function to search for a given value in the linked list
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void reverse() {            // Function to reverse the linked list
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }
};

int main() {
    LinkedList linkedList;
    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(4);
    linkedList.append(5);

    cout << "Original Linked List:" << endl;
    linkedList.display();
    int choice;
    cout << "Search your choice: " << endl;
    cin >> choice;
    int key =  choice;
    if (linkedList.search(key)) {
        cout << key << " is present in the linked list." << endl;
    }
    else {
        cout << key << " is not present in the linked list." << endl;
    }
    linkedList.reverse();
    cout << "Reversed Linked List:" << endl;
    linkedList.display();
    return 0;
}


