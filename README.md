# Tour Management System (DBMS Project)

A comprehensive and optimized Database Management System developed using **MySQL** to manage tour bookings, accommodations, payments, transportation, and customer interactions efficiently.

## 🌟 Advanced Database Features Implemented

- **Database Automation (Triggers)**: Implemented `booking_notification` trigger to automatically generate an unread alert in the `Notifications` table whenever a new booking is made.
- **Data Abstraction (Views)**: Created `CustomerBookingView` to securely fetch customer names, package names, travel dates, and statuses without exposing raw tables.
- **Encapsulation (Stored Procedures)**: Developed `GetUserBookings(uid)` to dynamically retrieve a specific user's historical booking list based on their User ID.
- **Performance Optimization (Indexing)**: Added `idx_destination` and `idx_booking_date` to accelerate data retrieval speed for large-scale production.

---

## 📊 Database Schema Architecture

The database consists of structured relational tables categorized under core modules:

### 1. User & Authentication Module
- `Users`: Handles user accounts, credentials, and access roles (`Admin`, `Customer`).
- `Employees`: Manages internal staff details, roles, and salaries.
- `TourGuides`: Tracks professional local guides and their experience.

### 2. Tours & Activities Module
- `Destinations`: Catalog of tourist locations worldwide.
- `TourPackages`: Curated travel plans mapped to creators (`Users`).
- `PackageDestination`: Many-to-Many mapping for packages covering multiple destinations.
- `Activities` & `PackageActivities`: Specific events/excursions linked to packages.

### 3. Core Booking & Logistics Module
- `Bookings`: Essential travel logs mapping users to packages, dates, and total costs.
- `Hotels` & `HotelBooking`: Tracks lodging availability, rates, and check-in/out metrics.
- `Transport` & `TransportBooking`: Logs vehicle capacities, operators, and departures.
- `PackageGuide`: Assigns dedicated guides to specific tour groups.

### 4. Financial & Support Operations
- `Payments`: Finalized transactions linked to payment status (`Paid`, `Pending`, `Failed`).
- `Refunds`: Handles booking cancellations and monetary reversals.
- `Expenses`: Logs backend company/operational costs.
- `Insurance`: Manages policy coverage values per booking.

### 5. Customer Engagement Module
- `Reviews`: Customer feedback loop with a dynamic score range (`CHECK BETWEEN 1 AND 5`).
- `Wishlist`: Saved preferences for prospective bookings.
- `Coupons`: Promotional discount enforcement rules.
- `Notifications`: System logs to alert users about active actions.
- `SupportTickets`: Tracks customer support issues and ticket states (`Open`, `Closed`).

---

## 📈 Analytical Reports & Business Intelligence Included

The project file incorporates several analytical queries designed for management decisions:
1. **Revenue Tracking**: Calculates cumulative sales generated from fully paid bookings.
2. **Trending Packages**: Ranks packages based on highest reservation volumes using `GROUP BY`.
3. **Financial Auditing**: Computes the absolute spending per customer using complex table joins.
4. **Quality Assurance**: Evaluates average user feedback ratings per package.
5. **Inventory Auditing**: Flags out-of-budget premium packages using independent Subqueries.

---

## 🚀 How to Run the Database Script
1. Open your MySQL Command Line Client or any UI Tool (like Workbench, phpMyAdmin).
2. Create the environment or directly source the file:
   ```sql
   SOURCE path/to/TourManagement.sql;