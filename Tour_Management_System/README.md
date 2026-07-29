# 🗺️ Tour Management System (DBMS & OOP Project)

A professional **Tour Management System** developed using **C++ (Object-Oriented Programming)** and **MySQL**. This project provides a complete solution for managing tour packages, customer bookings, payments, hotels, transport, tour guides, reviews, refunds, and administrative operations through a console-based application.

---

# 📌 Project Overview

The system is designed to automate the entire tour management process. It allows customers to browse tour packages, make bookings, complete payments, generate invoices, submit reviews, and manage reservations. Administrators can efficiently manage packages, hotels, transport, guides, payments, refunds, and system reports.

---

# 🚀 Features

## 👤 User Authentication
- Secure Login System
- Admin & Customer Roles
- Role-based Access Control

---

## 🎒 Tour Package Management
- View Tour Packages
- Add New Package
- Update Package
- Delete Package
- Search Packages by Destination

---

## 📅 Booking Management
- Book Tour Packages
- View Booking History
- Cancel Booking
- Booking Confirmation

---

## 💳 Payment System
- Make Payment
- Payment Status
- Payment Records
- Automatic Invoice Generation

---

## 🧾 Invoice Generation
- Booking Summary
- Customer Details
- Package Details
- Total Cost

---

## 🔔 Notification System
Implemented using **MySQL Trigger**

Whenever a customer books a package, the trigger automatically generates a booking notification.

---

## ⭐ Review System
Customers can:
- Give Rating (1–5)
- Write Comments
- View Reviews

---

## 🏨 Hotel Management
- View Hotels
- Add Hotel
- Hotel Information Management

---

## 🚌 Transport Management
- View Transport
- Add Transport
- Transport Information Management

---

## 🧑‍💼 Tour Guide Management
- View Tour Guides
- Add Tour Guide
- Guide Information Management

---

## 💰 Refund Management
- Cancel Booking
- Generate Refund Request
- Approve Refund
- Refund Status

---

## 📊 Reports & Statistics
- Revenue Report
- Booking Statistics
- Total Customers
- Total Packages
- Total Payments
- Total Refunds

---

## 💾 File Handling
- Save Booking Data
- Load Booking Data

---

# 🛠️ Technologies Used

| Technology | Purpose |
|------------|----------|
| C++ | Frontend Console Application |
| OOP | Object-Oriented Programming |
| MySQL | Database Backend |
| MySQL Workbench | Database Management |
| STL (Vector) | Data Storage |
| File Handling | Save & Load Data |

---

# 🗄️ Database Concepts Implemented

- Tables
- Primary Key
- Foreign Key
- Constraints
- Views
- Stored Procedures
- Triggers
- Indexing

---

# 📂 Database Modules

- Users
- Tour Packages
- Bookings
- Payments
- Refunds
- Hotels
- Transport
- Tour Guides
- Reviews
- Notifications

---

# 💻 Project Structure

```
Tour_Management_System
│
├── main.cpp
├── tour_Management.sql
├── README.md
```

---

# ▶️ How to Run

## Step 1

Clone the repository

```bash
git clone https://github.com/Motiursd/SQL-Projects.git
```

## Step 2

Open MySQL Workbench

Run

```sql
SOURCE tour_Management.sql;
```

---

## Step 3

Compile

```bash
g++ main.cpp -o TourManagement
```

---

## Step 4

Run

```bash
./TourManagement
```

or (Windows)

```bash
TourManagement.exe
```

---

# 🔑 Demo Login

## 👑 Admin

Email

```
admin@gmail.com
```

Password

```
admin123
```

---

## 👤 Customer

Email

```
motiur@gmail.com
```

Password

```
12345
```

---

# 📸 Project Screenshots

Add screenshots here.

Example:

```
screenshots/
    login.png
    customer_menu.png
    admin_menu.png
    booking.png
    payment.png
```

---

# 📈 Future Improvements

- Online Payment Gateway
- Email Notification
- QR Code Ticket
- PDF Invoice
- Customer Registration
- Password Encryption
- Search & Filter
- Analytics Dashboard

---

# 🎯 Learning Outcomes

This project demonstrates practical implementation of:

- Object-Oriented Programming
- Database Design
- MySQL Integration
- File Handling
- Console Application Development
- Data Structures
- Software Engineering Principles

---

# 👨‍💻 Developer

**Md. Motiur Rahman**

Department of Computer Science & Engineering (CSE)

International Islamic University Chittagong (IIUC)

GitHub: https://github.com/Motiursd

---

# 📄 License

This project is developed for educational purposes as a **DBMS & OOP academic project**.
