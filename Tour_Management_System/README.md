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
SOURCE path/to/tour_Management.sql;```

## 📊 Entity-Relationship (ER) Diagram

```mermaid
erDiagram
    USERS {
        int user_id PK
        varchar full_name
        varchar email UK
        varchar phone
        varchar password
        text address
        enum role
        timestamp created_at
    }
    DESTINATIONS {
        int destination_id PK
        varchar destination_name
        varchar country
        text description
    }
    TOUR_PACKAGES {
        int package_id PK
        varchar package_name
        varchar destination
        int duration_days
        decimal price
        int max_people
        text description
        varchar image_url
        int created_by FK
    }
    PACKAGE_DESTINATION {
        int pd_id PK
        int package_id FK
        int destination_id FK
    }
    BOOKINGS {
        int booking_id PK
        int user_id FK
        int package_id FK
        date booking_date
        date travel_date
        int total_people
        decimal total_cost
        enum booking_status
    }
    PAYMENTS {
        int payment_id PK
        int booking_id FK
        varchar payment_method
        decimal amount
        date payment_date
        enum payment_status
    }
    HOTELS {
        int hotel_id PK
        varchar hotel_name
        varchar location
        decimal rating
        int available_rooms
        decimal price_per_night
    }
    HOTEL_BOOKING {
        int hotel_booking_id PK
        int booking_id FK
        int hotel_id FK
        date check_in
        date check_out
    }
    TRANSPORT {
        int transport_id PK
        varchar transport_type
        varchar company_name
        int seat_capacity
        time departure_time
    }
    TRANSPORT_BOOKING {
        int transport_booking_id PK
        int booking_id FK
        int transport_id FK
    }
    REVIEWS {
        int review_id PK
        int user_id FK
        int package_id FK
        int rating
        text comment
        date review_date
    }
    WISHLIST {
        int wishlist_id PK
        int user_id FK
        int package_id FK
    }
    NOTIFICATIONS {
        int notification_id PK
        int user_id FK
        text message
        varchar status
        timestamp created_at
    }
    TOUR_GUIDES {
        int guide_id PK
        varchar guide_name
        varchar language_spoken
        int experience_years
        varchar phone
    }
    PACKAGE_GUIDE {
        int pg_id PK
        int package_id FK
        int guide_id FK
    }
    EMERGENCY_CONTACTS {
        int emergency_id PK
        int user_id FK
        varchar contact_name
        varchar relation_person
        varchar phone
    }
    INSURANCE {
        int insurance_id PK
        int booking_id FK
        varchar provider_name
        decimal insurance_amount
    }
    REFUNDS {
        int refund_id PK
        int booking_id FK
        decimal refund_amount
        date refund_date
        enum refund_status
    }
    SUPPORT_TICKETS {
        int ticket_id PK
        int user_id FK
        varchar subject
        text message
        enum ticket_status
    }
    ACTIVITIES {
        int activity_id PK
        varchar activity_name
        decimal activity_cost
        text description
    }
    PACKAGE_ACTIVITIES {
        int pa_id PK
        int package_id FK
        int activity_id FK
    }

    %% Relationship Rules
    USERS ||--o{ TOUR_PACKAGES : "creates"
    USERS ||--o{ BOOKINGS : "places"
    USERS ||--o{ REVIEWS : "writes"
    USERS ||--o{ WISHLIST : "saves"
    USERS ||--o{ NOTIFICATIONS : "receives"
    USERS ||--o{ EMERGENCY_CONTACTS : "has"
    USERS ||--o{ SUPPORT_TICKETS : "opens"
    
    TOUR_PACKAGES ||--o{ PACKAGE_DESTINATION : "contains"
    DESTINATIONS ||--o{ PACKAGE_DESTINATION : "linked_to"
    
    TOUR_PACKAGES ||--o{ BOOKINGS : "reserved_for"
    TOUR_PACKAGES ||--o{ REVIEWS : "gets"
    TOUR_PACKAGES ||--o{ WISHLIST : "added_to"
    
    TOUR_PACKAGES ||--o{ PACKAGE_GUIDE : "assigned_to"
    TOUR_GUIDES ||--o{ PACKAGE_GUIDE : "guides"
    
    TOUR_PACKAGES ||--o{ PACKAGE_ACTIVITIES : "includes"
    ACTIVITIES ||--o{ PACKAGE_ACTIVITIES : "has_actions"
    
    BOOKINGS ||--o{ PAYMENTS : "billed_by"
    BOOKINGS ||--o{ HOTEL_BOOKING : "has_hotel"
    HOTELS ||--o{ HOTEL_BOOKING : "provides_room"
    
    BOOKINGS ||--o{ TRANSPORT_BOOKING : "has_transport"
    TRANSPORT ||--o{ TRANSPORT_BOOKING : "provides_ride"
    
    BOOKINGS ||--o{ INSURANCE : "secured_by"
    BOOKINGS ||--o{ REFUNDS : "claims"
