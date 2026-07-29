# 🗺️ Tour Management System

<div align="center">

![C++](https://img.shields.io/badge/C++-17-blue?logo=c%2B%2B)
![MySQL](https://img.shields.io/badge/MySQL-8.0-orange?logo=mysql)
![OOP](https://img.shields.io/badge/OOP-Object%20Oriented-success)
![License](https://img.shields.io/badge/License-MIT-green)

A complete **Database Management System (DBMS)** project developed using **C++ (Object-Oriented Programming)** and **MySQL**.

Designed for efficient management of tour packages, bookings, hotels, payments, transport, tour guides, reviews, refunds, and administrative operations.

</div>

---

# 📖 Project Overview

The **Tour Management System** is a console-based application that automates the complete tour booking process.

Customers can browse tour packages, make bookings, complete payments, submit reviews, and manage reservations.

Administrators can efficiently manage packages, hotels, transport, payments, refunds, reports, and customers through a secure admin panel.

---

# ✨ Key Features

## 🔐 User Authentication

- Secure Login System
- Admin & Customer Roles
- Role-based Access Control

---

## 🎒 Tour Package Management

- View Tour Packages
- Add Tour Package
- Update Package
- Delete Package
- Search Packages

---

## 📅 Booking Management

- Book Tour
- View Booking History
- Cancel Booking
- Booking Confirmation

---

## 💳 Payment Management

- Make Payment
- Payment History
- Payment Status
- Invoice Generation

---

## 🧾 Invoice Generation

- Customer Information
- Package Information
- Total Cost
- Booking Summary

---

## ⭐ Review System

- Give Rating (1–5)
- Write Comments
- View Reviews

---

## 🏨 Hotel Management

- View Hotels
- Add Hotel
- Hotel Information

---

## 🚌 Transport Management

- View Transport
- Add Transport
- Transport Information

---

## 🧑‍💼 Tour Guide Management

- View Tour Guides
- Add Tour Guide
- Guide Information

---

## 💰 Refund Management

- Cancel Booking
- Refund Request
- Refund Approval
- Refund Status

---

## 🔔 Notification System

Implemented using **MySQL Trigger**

Whenever a booking is inserted, the trigger automatically creates a notification.

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
| C++ | Console Application |
| OOP | Object-Oriented Programming |
| MySQL | Database Backend |
| MySQL Connector/C++ | Database Connectivity |
| MySQL Workbench | Database Design |
| Git | Version Control |
| GitHub | Repository Hosting |

---

# 🗄️ Database Concepts

This project implements various DBMS concepts including:

- Tables
- Primary Keys
- Foreign Keys
- Constraints
- Views
- Stored Procedures
- Triggers
- Indexing
- Relationships
- Normalization

---

# 📚 Database Modules

- Users
- Tour Packages
- Destinations
- Bookings
- Payments
- Hotels
- Hotel Booking
- Transport
- Transport Booking
- Employees
- Reviews
- Coupons
- Wishlist
- Notifications
- Tour Guides
- Package Guide
- Emergency Contacts
- Insurance
- Expenses
- Activities
- Refunds
- Support Tickets

---

# 📁 Project Structure

```text
Tour_Management_System
│
├── main.cpp
├── tour_Management.sql
├── README.md
├── LICENSE
├── Project_Report.pdf
│
├── docs
│   ├── ER_Diagram.png
│   ├── Relational_Schema.png
│   └── Prisma_Diagram.png
│
└── screenshots
    ├── login.png
    ├── admin_menu.png
    ├── customer_menu.png
    ├── booking.png
    ├── payment.png
    └── statistics.png
```

---

# 🖼️ Database Design

## ER Diagram

![ER Diagram](docs/ER_Diagram.png)

---

## Relational Schema

![Relational Schema](docs/Relational_Schema.png)

---

## Prisma Diagram

![Prisma Diagram](docs/Prisma_Diagram.png)

---

# 📸 Project Screenshots

## Login Page

![Login](screenshots/login.png)

---

## Customer Menu

![Customer Menu](screenshots/customer_menu.png)

---

## Admin Menu

![Admin Menu](screenshots/admin_menu.png)

---

## Booking Module

![Booking](screenshots/booking.png)

---

## Payment Module

![Payment](screenshots/payment.png)

---

## Statistics Dashboard

![Statistics](screenshots/statistics.png)

---

# ▶️ How to Run

## Step 1

Clone the repository

```bash
git clone https://github.com/Motiursd/SQL-Projects.git
```

---

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

Linux

```bash
./TourManagement
```

Windows

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

# 🚀 Future Improvements

- Online Payment Gateway
- Email Notification
- QR Code Ticket
- PDF Invoice
- Password Encryption
- Customer Registration
- Search & Filter
- Analytics Dashboard
- Mobile Application
- Cloud Database Support

---

# 🎓 Learning Outcomes

This project demonstrates practical implementation of:

- Database Management System
- Object-Oriented Programming
- SQL Programming
- MySQL Integration
- File Handling
- Console Application Development
- Software Engineering Principles
- Database Design
- Relational Database Concepts

---

# 👨‍💻 Developer

**Md. Motiur Rahman**

**Student ID:** C243119

Department of Computer Science & Engineering (CSE)

International Islamic University Chittagong (IIUC)

**Course:** Database Management Systems Lab

**Course Code:** CSE 2424

**Course Teacher:** Mizanur Rahman

GitHub:
https://github.com/Motiursd

---

# 📄 License

This project is developed for educational purposes as a **Database Management Systems (DBMS) Lab Project**.

---

<div align="center">

## ⭐ If you like this project, don't forget to give it a Star ⭐

Thank you for visiting this repository.

</div>
