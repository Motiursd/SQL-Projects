#include <iostream>
#include <string>
#include <vector>

using namespace std;


class User {
public:
    string email;
    string password;
    string role;

    bool login(string e, string p) {

        if (e == "motiur@gmail.com" && p == "12345") {
            role = "Customer";
            return true;
        } else if (e == "admin@gmail.com" && p == "admin123") {
            role = "Admin";
            return true;
        }
        return false;
    }
};


class TourPackage {
public:
    int id;
    string name;
    string destination;
    double price;
    int duration;

    void displayPackage() {
        cout << "\n-----------------------------------" << endl;
        cout << "Package ID: " << id << endl;
        cout << "Package Name: " << name << endl;
        cout << "Destination: " << destination << endl;
        cout << "Price: " << price << " BDT" << endl;
        cout << "Duration: " << duration << " Days" << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    User currentUser;
    string email, password;

    cout << "=== Welcome to Tour Management System ===" << endl;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    if (currentUser.login(email, password)) {
        cout << "\nLogin Successful! Role: " << currentUser.role << endl;

        int choice;
        if (currentUser.role == "Customer") {
            do {
                cout << "\n--- Customer Menu ---" << endl;
                cout << "1. View Tour Packages" << endl;
                cout << "2. Book a Tour" << endl;
                cout << "3. View My Bookings" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 1) {
                    TourPackage p1 = {1, "Coxs Bazar Tour", "Coxs Bazar", 15000, 5};
                    TourPackage p2 = {2, "Sajek Valley Tour", "Sajek", 10000, 3};
                    p1.displayPackage();
                    p2.displayPackage();
                } else if (choice == 2) {
                    cout << "\nEnter Package ID to book: ";
                    int pid;
                    cin >> pid;
                    cout << "Booking successful for Package ID " << pid << "! Trigger sent to Notifications." << endl;
                }
            } while (choice != 4);
        }
    } else {
        cout << "\nInvalid Credentials!" << endl;
    }

    return 0;
}
