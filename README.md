# Tour Management System (Advanced DBMS Project)

A robust and scalable Database Management System designed using **MySQL** to handle a complete tourism and vacation booking infrastructure. 

## 🌟 Advanced Database Features Implemented
- **Relational Integrity**: 20+ normalization-optimized tables (Users, Bookings, Hotels, Payments, Insurance, Tour Guides, etc.).
- **Performance Optimization**: Created `INDEX` keys on frequently searched columns (`destination`, `booking_date`) to speed up query performance.
- **Data Abstraction**: Implemented `CustomerBookingView` to securely view user booking statuses without directly touching core tables.
- **Automation (Trigger)**: Added `booking_notification` trigger that automatically sends unread dashboard notifications instantly upon every new booking insert.
- **Encapsulation (Stored Procedure)**: Programmed `GetUserBookings(uid)` procedure to safely fetch customer-specific historical transaction and travel data.

## 📊 Analytics & Reporting Queries Included
- Total Revenue Calculation
- Most Popular/Top Booking Packages
- Comprehensive User Expenditures
- Subqueries for Packages Above Average Price
- Dynamic Product Review and Rating System
-
