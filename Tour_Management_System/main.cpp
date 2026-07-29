#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;


struct User
{
    int id;
    string name;
    string email;
    string password;
    string role;
};


struct TourPackage
{
    int id;
    string name;
    string destination;
    double price;
    int duration;
};


struct Booking
{
    int id;
    int userId;
    int packageId;
    string travelDate;
    int people;
    double cost;
    string status;
};


struct Payment
{
    int paymentId;
    int bookingId;
    string method;
    double amount;
    string status;
};


struct Refund
{
    int refundId;
    int bookingId;
    double amount;
    string status;
};

struct Hotel
{
    int id;
    string name;
    string location;
    double pricePerNight;
    int rating;
};


struct Transport
{
    int id;
    string type;
    string company;
    int seats;
};


struct TourGuide
{
    int id;
    string name;
    string phone;
    string language;
};

struct Review
{
    int id;
    int userId;
    int packageId;
    int rating;
    string comment;
};



vector<User> usersTable =
{
    {1,"Admin User","admin@gmail.com","admin123","Admin"},
    {2,"Motiur Rahman","motiur@gmail.com","12345","Customer"}
};

vector<TourPackage> packagesTable =
{
    {1,"Cox's Bazar Tour","Cox's Bazar",15000,5},
    {2,"Sajek Valley Tour","Sajek",10000,3},
    {3,"Bandarban Tour","Bandarban",12000,4},
    {4,"Saint Martin Tour","Saint Martin",18000,4}
};

vector<Booking> bookingsTable =
{
    {1,2,1,"2026-06-01",2,30000,"Confirmed"}
};

vector<Payment> paymentsTable;

vector<Refund> refundsTable;

vector<Review> reviewsTable;

vector<Hotel> hotelsTable =
{
    {1,"Sea Pearl","Cox's Bazar",5000,5},
    {2,"Sajek Resort","Sajek",3500,4}
};

vector<Transport> transportTable =
{
    {1,"Bus","Green Line",40},
    {2,"Flight","Biman Bangladesh",180}
};

vector<TourGuide> guidesTable =
{
    {1,"Rakib Hasan","01711111111","Bangla"},
    {2,"Rahim Ahmed","01822222222","English"}
};

vector<string> notificationsTable;



User currentUser;

bool isLoggedIn=false;



void connectToDatabase();

bool dbLogin(string,string);

void searchTour();

void updatePackage();

void deletePackage();

void makePayment(int,double);

void printInvoice(const Booking&);

void cancelBooking();

void viewPayments();

void viewRefunds();

void approveRefund();

void viewHotels();

void addHotel();

void viewTransport();

void addTransport();

void viewGuides();

void addGuide();

void addReview();

void viewReviews();

void revenueReport();

void statistics();

void saveBookings();

void loadBookings();

void runTrigger_bookingNotification(int);



void connectToDatabase()
{
    cout << "=============================================\n";
    cout << "   TOUR MANAGEMENT SYSTEM DATABASE\n";
    cout << "=============================================\n";
    cout << "Connecting to MySQL Server...\n";
    cout << "Server : 127.0.0.1:3306\n";
    cout << "Database : TourManagement\n";
    cout << "Connection Successful!\n";
    cout << "Indexes Loaded Successfully.\n";
    cout << "Trigger : booking_notification ACTIVE.\n";
    cout << "=============================================\n\n";
}


bool dbLogin(string email,string password)
{
    for(const auto &u : usersTable)
    {
        if(u.email==email && u.password==password)
        {
            currentUser=u;
            isLoggedIn=true;
            return true;
        }
    }

    return false;
}

//====================================================
// BOOKING TRIGGER
//====================================================

void runTrigger_bookingNotification(int userId)
{
    string msg="User ID "+to_string(userId)+" booked a tour successfully.";

    notificationsTable.push_back(msg);
}



void searchTour()
{
    cin.ignore();

    string destination;

    cout<<"\nEnter Destination : ";

    getline(cin,destination);

    bool found=false;

    cout<<"\n========== SEARCH RESULT ==========\n";

    for(const auto &p:packagesTable)
    {
        if(p.destination==destination)
        {
            found=true;

            cout<<"Package ID : "<<p.id<<endl;
            cout<<"Name       : "<<p.name<<endl;
            cout<<"Destination: "<<p.destination<<endl;
            cout<<"Price      : "<<p.price<<" BDT"<<endl;
            cout<<"Duration   : "<<p.duration<<" Days"<<endl;
            cout<<"----------------------------------"<<endl;
        }
    }

    if(!found)
    {
        cout<<"No Package Found.\n";
    }
}


void updatePackage()
{
    int id;

    cout<<"\nEnter Package ID : ";
    cin>>id;

    for(auto &p:packagesTable)
    {
        if(p.id==id)
        {
            cin.ignore();

            cout<<"New Package Name : ";
            getline(cin,p.name);

            cout<<"New Destination : ";
            getline(cin,p.destination);

            cout<<"New Price : ";
            cin>>p.price;

            cout<<"New Duration : ";
            cin>>p.duration;

            cout<<"\nPackage Updated Successfully!\n";

            return;
        }
    }

    cout<<"Package Not Found!\n";
}



void deletePackage()
{
    int id;

    cout<<"\nEnter Package ID : ";

    cin>>id;

    for(auto it=packagesTable.begin();it!=packagesTable.end();it++)
    {
        if(it->id==id)
        {
            packagesTable.erase(it);

            cout<<"\nPackage Deleted Successfully!\n";

            return;
        }
    }

    cout<<"Package Not Found!\n";
}



void makePayment(int bookingId, double amount)
{
    int choice;

    cout << "\n========== PAYMENT ==========\n";
    cout << "1. bKash\n";
    cout << "2. Nagad\n";
    cout << "3. Credit/Debit Card\n";
    cout << "Choose Payment Method : ";
    cin >> choice;

    string method;

    switch(choice)
    {
        case 1:
            method = "bKash";
            break;

        case 2:
            method = "Nagad";
            break;

        case 3:
            method = "Card";
            break;

        default:
            cout << "Invalid Payment Method!\n";
            return;
    }

    Payment p;

    p.paymentId = paymentsTable.size() + 1;
    p.bookingId = bookingId;
    p.method = method;
    p.amount = amount;
    p.status = "Paid";

    paymentsTable.push_back(p);

    cout << "\n====================================\n";
    cout << "Payment Successful!\n";
    cout << "Method : " << method << endl;
    cout << "Amount : " << amount << " BDT\n";
    cout << "====================================\n";
}



void printInvoice(const Booking &b)
{
    string packageName = "";

    for(const auto &p : packagesTable)
    {
        if(p.id == b.packageId)
        {
            packageName = p.name;
            break;
        }
    }

    cout << "\n=========================================\n";
    cout << "           TOUR INVOICE\n";
    cout << "=========================================\n";

    cout << "Booking ID   : " << b.id << endl;
    cout << "Customer ID  : " << b.userId << endl;
    cout << "Package      : " << packageName << endl;
    cout << "Travel Date  : " << b.travelDate << endl;
    cout << "People       : " << b.people << endl;
    cout << "Total Cost   : " << b.cost << " BDT" << endl;
    cout << "Status       : " << b.status << endl;

    cout << "=========================================\n";
    cout << "Thank You For Booking With Us\n";
    cout << "=========================================\n";
}


void viewPayments()
{
    cout << "\n========== PAYMENT REPORT ==========\n";

    if(paymentsTable.empty())
    {
        cout << "No Payment Records Found!\n";
        return;
    }

    cout << left
         << setw(12) << "Pay ID"
         << setw(12) << "Book ID"
         << setw(15) << "Method"
         << setw(15) << "Amount"
         << setw(15) << "Status"
         << endl;

    cout << "-------------------------------------------------------------\n";

    for(const auto &p : paymentsTable)
    {
        cout << left
             << setw(12) << p.paymentId
             << setw(12) << p.bookingId
             << setw(15) << p.method
             << setw(15) << p.amount
             << setw(15) << p.status
             << endl;
    }
}


void cancelBooking()
{
    int bookingId;

    cout << "\nEnter Booking ID to Cancel : ";
    cin >> bookingId;

    for(auto &b : bookingsTable)
    {
        if(b.id == bookingId && b.userId == currentUser.id)
        {
            if(b.status == "Cancelled")
            {
                cout << "\nBooking Already Cancelled!\n";
                return;
            }

            b.status = "Cancelled";

            Refund r;

            r.refundId = refundsTable.size() + 1;
            r.bookingId = bookingId;
            r.amount = b.cost;
            r.status = "Pending";

            refundsTable.push_back(r);

            cout << "\n=====================================\n";
            cout << "Booking Cancelled Successfully!\n";
            cout << "Refund Request Created Successfully!\n";
            cout << "Refund Amount : " << b.cost << " BDT\n";
            cout << "=====================================\n";

            return;
        }
    }

    cout << "\nBooking Not Found!\n";
}


void viewRefunds()
{
    cout << "\n========== REFUND REPORT ==========\n";

    if(refundsTable.empty())
    {
        cout << "No Refund Requests Found.\n";
        return;
    }

    cout << left
         << setw(12) << "Refund ID"
         << setw(12) << "Booking"
         << setw(15) << "Amount"
         << setw(15) << "Status"
         << endl;

    cout << "-------------------------------------------------\n";

    for(const auto &r : refundsTable)
    {
        cout << left
             << setw(12) << r.refundId
             << setw(12) << r.bookingId
             << setw(15) << r.amount
             << setw(15) << r.status
             << endl;
    }
}


void approveRefund()
{
    int refundId;

    cout << "\nEnter Refund ID : ";
    cin >> refundId;

    for(auto &r : refundsTable)
    {
        if(r.refundId == refundId)
        {
            if(r.status == "Approved")
            {
                cout << "\nRefund Already Approved!\n";
                return;
            }

            r.status = "Approved";

            cout << "\n=================================\n";
            cout << "Refund Approved Successfully!\n";
            cout << "=================================\n";

            return;
        }
    }

    cout << "\nRefund ID Not Found!\n";
}


void viewHotels()
{
    cout << "\n========== HOTEL LIST ==========\n";

    if(hotelsTable.empty())
    {
        cout << "No Hotels Available.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Hotel Name"
         << setw(20) << "Location"
         << setw(15) << "Price"
         << setw(10) << "Rating"
         << endl;

    cout << "-----------------------------------------------------------------\n";

    for(const auto &h : hotelsTable)
    {
        cout << left
             << setw(10) << h.id
             << setw(25) << h.name
             << setw(20) << h.location
             << setw(15) << h.pricePerNight
             << setw(10) << h.rating
             << endl;
    }
}


void addHotel()
{
    Hotel h;

    h.id = hotelsTable.size()+1;

    cin.ignore();

    cout << "\nHotel Name : ";
    getline(cin,h.name);

    cout << "Location : ";
    getline(cin,h.location);

    cout << "Price Per Night : ";
    cin >> h.pricePerNight;

    cout << "Rating (1-5) : ";
    cin >> h.rating;

    hotelsTable.push_back(h);

    cout << "\nHotel Added Successfully!\n";
}


void viewTransport()
{
    cout << "\n========== TRANSPORT LIST ==========\n";

    if(transportTable.empty())
    {
        cout << "No Transport Available.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Type"
         << setw(25) << "Company"
         << setw(10) << "Seats"
         << endl;

    cout << "-----------------------------------------------------------\n";

    for(const auto &t : transportTable)
    {
        cout << left
             << setw(10) << t.id
             << setw(20) << t.type
             << setw(25) << t.company
             << setw(10) << t.seats
             << endl;
    }
}


void addTransport()
{
    Transport t;

    t.id = transportTable.size()+1;

    cin.ignore();

    cout << "\nTransport Type : ";
    getline(cin,t.type);

    cout << "Company Name : ";
    getline(cin,t.company);

    cout << "Total Seats : ";
    cin >> t.seats;

    transportTable.push_back(t);

    cout << "\nTransport Added Successfully!\n";
}


void viewGuides()
{
    cout << "\n========== TOUR GUIDE LIST ==========\n";

    if(guidesTable.empty())
    {
        cout << "No Tour Guides Available.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Guide Name"
         << setw(20) << "Phone"
         << setw(20) << "Language"
         << endl;

    cout << "----------------------------------------------------------------\n";

    for(const auto &g : guidesTable)
    {
        cout << left
             << setw(10) << g.id
             << setw(25) << g.name
             << setw(20) << g.phone
             << setw(20) << g.language
             << endl;
    }
}

void addGuide()
{
    TourGuide g;

    g.id = guidesTable.size()+1;

    cin.ignore();

    cout << "\nGuide Name : ";
    getline(cin,g.name);

    cout << "Phone : ";
    getline(cin,g.phone);

    cout << "Language : ";
    getline(cin,g.language);

    guidesTable.push_back(g);

    cout << "\nTour Guide Added Successfully!\n";
}


void addReview()
{
    Review r;

    r.id = reviewsTable.size() + 1;
    r.userId = currentUser.id;

    cout << "\nEnter Package ID : ";
    cin >> r.packageId;

    do
    {
        cout << "Rating (1-5) : ";
        cin >> r.rating;

        if(r.rating < 1 || r.rating > 5)
            cout << "Invalid Rating! Please Enter Between 1 and 5.\n";

    }while(r.rating < 1 || r.rating > 5);

    cin.ignore();

    cout << "Comment : ";
    getline(cin,r.comment);

    reviewsTable.push_back(r);

    cout << "\nReview Submitted Successfully!\n";
}


void viewReviews()
{
    cout << "\n========== CUSTOMER REVIEWS ==========\n";

    if(reviewsTable.empty())
    {
        cout << "No Reviews Available.\n";
        return;
    }

    for(const auto &r : reviewsTable)
    {
        cout << "\nReview ID : " << r.id << endl;
        cout << "User ID   : " << r.userId << endl;
        cout << "Package ID: " << r.packageId << endl;
        cout << "Rating    : " << r.rating << "/5" << endl;
        cout << "Comment   : " << r.comment << endl;
        cout << "--------------------------------------\n";
    }
}


void revenueReport()
{
    double totalRevenue = 0;

    for(const auto &p : paymentsTable)
    {
        if(p.status == "Paid")
        {
            totalRevenue += p.amount;
        }
    }

    cout << "\n========== REVENUE REPORT ==========\n";

    cout << "Total Payments : "
         << paymentsTable.size() << endl;

    cout << "Total Revenue  : "
         << totalRevenue
         << " BDT" << endl;
}


void statistics()
{
    cout << "\n========== SYSTEM DASHBOARD ==========\n";

    cout << "Total Users        : "
         << usersTable.size() << endl;

    cout << "Total Packages     : "
         << packagesTable.size() << endl;

    cout << "Total Bookings     : "
         << bookingsTable.size() << endl;

    cout << "Total Payments     : "
         << paymentsTable.size() << endl;

    cout << "Total Refunds      : "
         << refundsTable.size() << endl;

    cout << "Total Hotels       : "
         << hotelsTable.size() << endl;

    cout << "Total Transport    : "
         << transportTable.size() << endl;

    cout << "Total Tour Guides  : "
         << guidesTable.size() << endl;

    cout << "Total Reviews      : "
         << reviewsTable.size() << endl;

    revenueReport();
}

void saveBookings()
{
    ofstream file("bookings.txt");

    if(!file)
    {
        cout << "Error Saving File!\n";
        return;
    }

    for(const auto &b : bookingsTable)
    {
        file
        << b.id << " "
        << b.userId << " "
        << b.packageId << " "
        << b.travelDate << " "
        << b.people << " "
        << b.cost << " "
        << b.status << endl;
    }

    file.close();
}


void loadBookings()
{
    ifstream file("bookings.txt");

    if(!file)
        return;

    bookingsTable.clear();

    Booking b;

    while(file >>
          b.id >>
          b.userId >>
          b.packageId >>
          b.travelDate >>
          b.people >>
          b.cost >>
          b.status)
    {
        bookingsTable.push_back(b);
    }

    file.close();
}

int main()
{
    loadBookings();

    connectToDatabase();

    string email,password;

    cout << "=========================================\n";
    cout << "     TOUR MANAGEMENT SYSTEM\n";
    cout << "=========================================\n";

    cout << "Email    : ";
    cin >> email;

    cout << "Password : ";
    cin >> password;

    if(!dbLogin(email,password))
    {
        cout << "\nInvalid Email or Password!\n";
        return 0;
    }

    cout << "\nLogin Successful!\n";
    cout << "Welcome " << currentUser.name << endl;
    cout << "Role : " << currentUser.role << endl;

    int choice;

    //====================================================
    // CUSTOMER MENU
    //====================================================

    if(currentUser.role=="Customer")
    {
        do
        {
            cout << "\n=========================================\n";
            cout << "           CUSTOMER PANEL\n";
            cout << "=========================================\n";

            cout << "1. View Tour Packages\n";
            cout << "2. Search Tour\n";
            cout << "3. Book Tour\n";
            cout << "4. View My Bookings\n";
            cout << "5. Cancel Booking\n";
            cout << "6. Add Review\n";
            cout << "7. Exit\n";

            cout << "\nEnter Choice : ";
            cin >> choice;

            switch(choice)
            {
                case 1:

                    cout << "\n========== TOUR PACKAGES ==========\n";

                    for(const auto &p : packagesTable)
                    {
                        cout << "\nPackage ID   : " << p.id << endl;
                        cout << "Package Name : " << p.name << endl;
                        cout << "Destination  : " << p.destination << endl;
                        cout << "Price        : " << p.price << " BDT" << endl;
                        cout << "Duration     : " << p.duration << " Days" << endl;
                        cout << "--------------------------------------\n";
                    }

                    break;

                case 2:

                    searchTour();

                    break;

                case 3:
                {
                    int packageId;
                    int people;
                    string travelDate;

                    cout << "\nEnter Package ID : ";
                    cin >> packageId;

                    bool found=false;
                    double price=0;

                    for(const auto &p:packagesTable)
                    {
                        if(p.id==packageId)
                        {
                            found=true;
                            price=p.price;
                            break;
                        }
                    }

                    if(!found)
                    {
                        cout<<"Package Not Found!\n";
                        break;
                    }

                    cout<<"Number of People : ";
                    cin>>people;

                    try
                    {
                        if(people<=0)
                            throw "Invalid Number of People!";
                    }
                    catch(const char *msg)
                    {
                        cout<<msg<<endl;
                        break;
                    }

                    cout<<"Travel Date (YYYY-MM-DD): ";
                    cin>>travelDate;

                    double totalCost=price*people;

                    Booking newBooking;

                    newBooking.id=bookingsTable.size()+1;
                    newBooking.userId=currentUser.id;
                    newBooking.packageId=packageId;
                    newBooking.travelDate=travelDate;
                    newBooking.people=people;
                    newBooking.cost=totalCost;
                    newBooking.status="Confirmed";

                    bookingsTable.push_back(newBooking);

                    runTrigger_bookingNotification(currentUser.id);

                    makePayment(newBooking.id,totalCost);

                    printInvoice(newBooking);

                    cout<<"\nBooking Completed Successfully!\n";

                    break;
                }

                case 4:

                    cout<<"\n========== MY BOOKINGS ==========\n";

                    for(const auto &b:bookingsTable)
                    {
                        if(b.userId==currentUser.id)
                        {
                            cout<<"\nBooking ID : "<<b.id<<endl;
                            cout<<"Package ID : "<<b.packageId<<endl;
                            cout<<"Travel Date: "<<b.travelDate<<endl;
                            cout<<"People     : "<<b.people<<endl;
                            cout<<"Cost       : "<<b.cost<<" BDT"<<endl;
                            cout<<"Status     : "<<b.status<<endl;
                            cout<<"------------------------------"<<endl;
                        }
                    }

                    break;

                case 5:

                    cancelBooking();

                    break;

                case 6:

                    addReview();

                    break;

                case 7:

                    saveBookings();

                    cout<<"\nThank You For Using Tour Management System.\n";

                    break;

                default:

                    cout<<"\nInvalid Choice!\n";
            }

        }while(choice!=7);
    }


    else if(currentUser.role=="Admin")
    {
        do
        {
            cout << "\n=========================================\n";
            cout << "             ADMIN PANEL\n";
            cout << "=========================================\n";

            cout << "1. Add Tour Package\n";
            cout << "2. Update Tour Package\n";
            cout << "3. Delete Tour Package\n";
            cout << "4. View Hotels\n";
            cout << "5. Add Hotel\n";
            cout << "6. View Transport\n";
            cout << "7. Add Transport\n";
            cout << "8. View Tour Guides\n";
            cout << "9. Add Tour Guide\n";
            cout << "10. View All Bookings\n";
            cout << "11. View Notifications\n";
            cout << "12. View Payments\n";
            cout << "13. View Refunds\n";
            cout << "14. Approve Refund\n";
            cout << "15. Revenue Report\n";
            cout << "16. System Statistics\n";
            cout << "17. View Reviews\n";
            cout << "18. Exit\n";

            cout << "\nEnter Choice : ";
            cin >> choice;

            switch(choice)
            {

                case 1:
                {
                    TourPackage p;

                    p.id = packagesTable.size()+1;

                    cin.ignore();

                    cout << "Package Name : ";
                    getline(cin,p.name);

                    cout << "Destination : ";
                    getline(cin,p.destination);

                    cout << "Price : ";
                    cin >> p.price;

                    cout << "Duration (Days): ";
                    cin >> p.duration;

                    packagesTable.push_back(p);

                    cout << "\nPackage Added Successfully!\n";

                    break;
                }

                case 2:

                    updatePackage();

                    break;

                case 3:

                    deletePackage();

                    break;

                case 4:

                    viewHotels();

                    break;

                case 5:

                    addHotel();

                    break;

                case 6:

                    viewTransport();

                    break;

                case 7:

                    addTransport();

                    break;

                case 8:

                    viewGuides();

                    break;

                case 9:

                    addGuide();

                    break;

                case 10:

                    cout << "\n========== ALL BOOKINGS ==========\n";

                    for(const auto &b : bookingsTable)
                    {
                        cout << "\nBooking ID : " << b.id << endl;
                        cout << "User ID    : " << b.userId << endl;
                        cout << "Package ID : " << b.packageId << endl;
                        cout << "Travel Date: " << b.travelDate << endl;
                        cout << "People     : " << b.people << endl;
                        cout << "Cost       : " << b.cost << " BDT" << endl;
                        cout << "Status     : " << b.status << endl;
                        cout << "---------------------------------------\n";
                    }

                    break;

                case 11:

                    cout << "\n========== NOTIFICATIONS ==========\n";

                    if(notificationsTable.empty())
                    {
                        cout << "No Notifications Available.\n";
                    }
                    else
                    {
                        for(const auto &n : notificationsTable)
                        {
                            cout << "- " << n << endl;
                        }
                    }

                    break;

                case 12:

                    viewPayments();

                    break;

                case 13:

                    viewRefunds();

                    break;

                case 14:

                    approveRefund();

                    break;

                case 15:

                    revenueReport();

                    break;

                case 16:

                    statistics();

                    break;

                case 17:

                    viewReviews();

                    break;

                case 18:

                    saveBookings();

                    cout << "\nAdmin Logged Out Successfully.\n";

                    break;

                default:

                    cout << "\nInvalid Choice!\n";
            }

        }
        while(choice != 18);
    }


    else
    {
        cout << "\nUnknown User Role!\n";
    }


    saveBookings();

    cout << "\n=========================================\n";
    cout << " Thank You For Using Tour Management System\n";
    cout << "=========================================\n";

    return 0;
}

