# 🗺️ Tour Management System (DBMS & OOP Project)

An enterprise-grade, optimized Database Management System developed using **C++** (Object-Oriented Programming) for the frontend and **MySQL** for the robust database backend. This system manages tour packages, dynamic customer bookings, hotel/transport logistics, and customer reviews seamlessly.

---

## 🌟 Core System Highlights & Advanced Features

- **Database Automation (Triggers)**: Whenever a customer books a package, the `booking_notification` trigger instantly generates a real-time, unread alert in the `Notifications` table.
- **Data Abstraction (Views)**: Built `CustomerBookingView` to securely join tables and display booking records without exposing sensitive raw user data.
- **Encapsulation (Stored Procedures)**: Developed `GetUserBookings(uid)` to dynamically fetch historical booking logs for a targeted user ID.
- **Performance Optimization (Indexing)**: Applied `idx_destination` and `idx_booking_date` to accelerate queries on large production datasets.

---

## 💻 Tech Stack Implemented

* **Frontend Console**: C++ (OOP Concepts, Encapsulation, Structs, Dynamic Vector Tables)
* **Database Backend**: MySQL Server 8.0
* **Database Tools**: MySQL Workbench, Command-Line Client

---

## 📊 Database Schema Architecture

The relational database architecture is strictly normalized and divided into functional modules:
1. **User & Authentication**: `Users` (Admin/Customer roles), `Employees`, `TourGuides`.
2. **Logistics & Bookings**: `Bookings`, `Hotels`, `HotelBooking`, `Transport`, `TransportBooking`.
3. **Financials & Feedback**: `Payments`, `Refunds`, `Expenses`, `Reviews` (with `CHECK BETWEEN 1 AND 5` constraint), `Notifications`.

---

## 🛠️ How to Set Up & Run the Project

### 1. Database Setup (MySQL)
Open your MySQL Command Line Client or MySQL Workbench and run:
```sql
SOURCE path/to/tour_Management.sql;
