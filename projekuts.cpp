#include <iostream>
#include <string>
using namespace std;

// Struct to store contact information
struct Contact {
    string name;
    string phoneNumber;
};

// Node untuk linked list kontak
struct Node {
    Contact data;
    Node* next;
};

// Class untuk linked list kontak
class ContactList {
private:
    Node* head;

public:
    // Constructor
    ContactList() {
        head = nullptr;
    }

    // Method for adding new contacts
    void addContact(Contact newContact) {
        Node* newNode = new Node;
        newNode->data = newContact;
        newNode->next = head;
        head = newNode;
    }

    // Method delete contacts by name
    void deleteContact(string name) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data.name == name) {
                if (previous != nullptr) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << "Kontak '" << name << "' berhasil dihapus." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Kontak '" << name << "' tidak ditemukan." << endl;
    }

    // Method to display the contact list
    void displayContacts() {
        if (head == nullptr) {
            cout << "Daftar kontak kosong." << endl;
            return;
        }

        cout << "Daftar Kontak:" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << "Nama : " << current->data.name << ", Nomor Telepon : " << current->data.phoneNumber << endl;
            current = current->next;
        }
    }
};

int main() {
    ContactList contactList;

    // Add contacts
    contactList.addContact({"Salina Putri", "089873190021"});
    contactList.addContact({"Dila Rahayu", "083853142697"});
    contactList.addContact({"Azizah Khoerunnisa", "081345874337"});

    // Displays the contact list
    contactList.displayContacts();

    // Delete contact
    contactList.deleteContact("Dila Rahayu");

    // Displays contact list after deletion
    contactList.displayContacts();

    return 0;
}