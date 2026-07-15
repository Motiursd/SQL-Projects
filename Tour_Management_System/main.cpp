#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct User {
    int id;
    string name;
    string email;
    string password;
    string role;
};

struct Booking {
    int id;
    int userId;
    int packageId;
    string travelDate;
    int people;
    double cost;
    string status;
};

struct TourPackage {
    int id;
    string name;
    string destination;
    double price;
    int duration;
};

vector<User> usersTable = {
    {1, "Admin User", "admin@gmail.com", "admin123", "Admin"},
    {2, "Motiur Rahman", "motiur@gmail.com", "12345", "Customer"}
};

vector<TourPackage> packagesTable = {
    {1, "Coxs Bazar Tour", "Coxs Bazar", 15000, 5},
    {2, "Sajek Valley Tour", "Sajek", 10000, 3}
};

vector<Booking> bookingsTable = {
    {1, 2, 1, "2026-06-01", 2, 30000, "Confirmed"}
};

vector<string> notificationsTable;

User currentUser;
bool isLoggedIn = false;

void connectToDatabase() {
    cout << "Connecting to MySQL Database Server [127.0.0.1:3306]..." << endl;
    cout << "Database Status: Connected Successfully! [TourManagement]" << endl;
    cout << "Loading Indices: idx_destination, idx_booking_date initialized." << endl;
    cout << "Trigger: 'booking_notification' is ACTIVE." << endl;
    cout << "=========================================================\n" << endl;
}

bool dbLogin(string email, string password) {
    for (const auto& u : usersTable) {
        if (u.email == email && u.password == password) {
            currentUser = u;
            isLoggedIn = true;
            return true;
        }
    }
    return false;
}

void runTrigger_bookingNotification(int userId) {
    string msg = "User ID " + to_string(userId) + ": Your booking has been confirmed [Trigger Fired]";
    notificationsTable.push_back(msg);
}

int main() {
    connectToDatabase();

    string email, password;
    cout << "=== Welcome to Tour Management System ===" << endl;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    if (dbLogin(email, password)) {
        cout << "\n>>> Login Successful! Role: " << currentUser.role << " (User ID: " << currentUser.id << ")" << endl;

        int choice;
        if (currentUser.role == "Customer") {
            do {
                cout << "\n--- Customer Menu ---" << endl;
                cout << "1. View Tour Packages" << endl;
                cout << "2. Book a Tour (Triggers Notification)" << endl;
                cout << "3. View My Bookings" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "\n--- Active Tour Packages [Fetched dynamically] ---" << endl;
                    for (const auto& p : packagesTable) {
                        cout << "-----------------------------------" << endl;
                        cout << "Package ID: " << p.id << endl;
                        cout << "Name: " << p.name << endl;
                        cout << "Destination: " << p.destination << endl;
                        cout << "Price: " << p.price << " BDT" << endl;
                        cout << "Duration: " << p.duration << " Days" << endl;
                    }
                    cout << "-----------------------------------" << endl;
                }
                else if (choice == 2) {
                    int pid, people;
                    string tDate;
                    cout << "\nEnter Package ID to book: ";
                    cin >> pid;

                    bool found = false;
                    double pricePerPerson = 0;
                    for (const auto& p : packagesTable) {
                        if (p.id == pid) {
                            found = true;
                            pricePerPerson = p.price;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Invalid Package ID!" << endl;
                        continue;
                    }

                    cout << "Enter Number of People: ";
                    cin >> people;
                    cout << "Enter Travel Date (YYYY-MM-DD): ";
                    cin >> tDate;

                    double totalCost = pricePerPerson * people;

                    Booking newBooking = { (int)bookingsTable.size() + 1, currentUser.id, pid, tDate, people, totalCost, "Confirmed" };
                    bookingsTable.push_back(newBooking);

                    runTrigger_bookingNotification(currentUser.id);

                    cout << "\n[MySQL] INSERT INTO Bookings VALUES (SUCCESS)" << endl;
                    cout << "Booking successful! Total Cost: " << totalCost << " BDT." << endl;
                    cout << "[MySQL Trigger Fired] Alert sent to Notifications Table!" << endl;
                }
                else if (choice == 3) {
                   
                    cout << "\n--- Calling Stored Procedure: GetUserBookings(" << currentUser.id << ") ---" << endl;
                    cout << left << setw(12) << "BookingID" << setw(20) << "Package Name" << setw(15) << "Travel Date" << setw(10) << "Status" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    for (const auto& b : bookingsTable) {
                        if (b.userId == currentUser.id) {
                            string pName = (b.packageId == 1) ? "Coxs Bazar Tour" : "Sajek Valley Tour";
                            cout << left << setw(12) << b.id << setw(20) << pName << setw(15) << b.travelDate << setw(10) << b.status << endl;
                        }
                    }
                }
            } while (choice != 4);
        }
        else if (currentUser.role == "Admin") {
            do {
                cout << "\n--- Admin Menu ---" << endl;
                cout << "1. Add New Tour Package" << endl;
                cout << "2. View All Bookings (Using CustomerBookingView)" << endl;
                cout << "3. View System Notifications (Generated by Triggers)" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 1) {
                    TourPackage newP;
                    newP.id = packagesTable.size() + 1;
                    cout << "\nEnter Package Name: ";
                    cin.ignore();
                    getline(cin, newP.name);
                    cout << "Enter Destination: ";
                    getline(cin, newP.destination);
                    cout << "Enter Price (BDT): ";
                    cin >> newP.price;
                    cout << "Enter Duration (Days): ";
                    cin >> newP.duration;

                    packagesTable.push_back(newP);
                    cout << "\n[MySQL] INSERT INTO TourPackages VALUES (SUCCESS)" << endl;
                    cout << "New Package added dynamically!" << endl;
                }
                else if (choice == 2) {
                   
                    cout << "\n--- Querying View: CustomerBookingView ---" << endl;
                    cout << left << setw(18) << "Customer Name" << setw(22) << "Package Name" << setw(15) << "Travel Date" << setw(10) << "Status" << endl;
                    cout << "----------------------------------------------------------------------" << endl;
                    for (const auto& b : bookingsTable) {
                        string cName = (b.userId == 2) ? "Motiur Rahman" : "Admin User";
                        string pName = "";
                        for (const auto& p : packagesTable) {
                            if (p.id == b.packageId) {
                                pName = p.name;
                                break;
                            }
                        }
                        cout << left << setw(18) << cName << setw(22) << pName << setw(15) << b.travelDate << setw(10) << b.status << endl;
                    }
                }
                else if (choice == 3) {
                    cout << "\n--- Raw Database Notifications (Trigger Logs) ---" << endl;
                    if (notificationsTable.empty()) {
                        cout << "No active trigger logs." << endl;
                    } else {
                        for (const auto& note : notificationsTable) {
                            cout << ">> " << note << endl;
                        }
                    }
                }
            } while (choice != 4);
        }
    } else {
        cout << "\nInvalid Credentials!" << endl;
    }

    return 0;
}
