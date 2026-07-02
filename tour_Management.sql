DROP DATABASE IF EXISTS TourManagement;

CREATE DATABASE TourManagement;

USE TourManagement;

CREATE TABLE Users(
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    full_name VARCHAR(100),
    email VARCHAR(100) UNIQUE,
    phone VARCHAR(20),
    password VARCHAR(100),
    address TEXT,
    role ENUM('Admin','Customer'),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Destinations(
    destination_id INT PRIMARY KEY AUTO_INCREMENT,
    destination_name VARCHAR(100),
    country VARCHAR(100),
    description TEXT
);

CREATE TABLE TourPackages(
    package_id INT PRIMARY KEY AUTO_INCREMENT,
    package_name VARCHAR(100),
    destination VARCHAR(100),
    duration_days INT,
    price DECIMAL(10,2),
    max_people INT,
    description TEXT,
    image_url VARCHAR(255),
    created_by INT,

    FOREIGN KEY(created_by)
    REFERENCES Users(user_id)
);

CREATE TABLE PackageDestination(
    pd_id INT PRIMARY KEY AUTO_INCREMENT,
    package_id INT,
    destination_id INT,

    FOREIGN KEY(package_id)
    REFERENCES TourPackages(package_id),

    FOREIGN KEY(destination_id)
    REFERENCES Destinations(destination_id)
);

CREATE TABLE Bookings(
    booking_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    package_id INT,
    booking_date DATE,
    travel_date DATE,
    total_people INT,
    total_cost DECIMAL(10,2),

    booking_status ENUM(
        'Pending',
        'Confirmed',
        'Cancelled'
    ),

    FOREIGN KEY(user_id)
    REFERENCES Users(user_id),

    FOREIGN KEY(package_id)
    REFERENCES TourPackages(package_id)
);

CREATE TABLE Payments(
    payment_id INT PRIMARY KEY AUTO_INCREMENT,
    booking_id INT,
    payment_method VARCHAR(50),
    amount DECIMAL(10,2),
    payment_date DATE,

    payment_status ENUM(
        'Paid',
        'Pending',
        'Failed'
    ),

    FOREIGN KEY(booking_id)
    REFERENCES Bookings(booking_id)
);

CREATE TABLE Hotels(
    hotel_id INT PRIMARY KEY AUTO_INCREMENT,
    hotel_name VARCHAR(100),
    location VARCHAR(100),
    rating DECIMAL(2,1),
    available_rooms INT,
    price_per_night DECIMAL(10,2)
);

CREATE TABLE HotelBooking(
    hotel_booking_id INT PRIMARY KEY AUTO_INCREMENT,
    booking_id INT,
    hotel_id INT,
    check_in DATE,
    check_out DATE,

    FOREIGN KEY(booking_id)
    REFERENCES Bookings(booking_id),

    FOREIGN KEY(hotel_id)
    REFERENCES Hotels(hotel_id)
);

CREATE TABLE Transport(
    transport_id INT PRIMARY KEY AUTO_INCREMENT,
    transport_type VARCHAR(50),
    company_name VARCHAR(100),
    seat_capacity INT,
    departure_time TIME
);

CREATE TABLE TransportBooking(
    transport_booking_id INT PRIMARY KEY AUTO_INCREMENT,
    booking_id INT,
    transport_id INT,

    FOREIGN KEY(booking_id)
    REFERENCES Bookings(booking_id),

    FOREIGN KEY(transport_id)
    REFERENCES Transport(transport_id)
);

CREATE TABLE Employees(
    employee_id INT PRIMARY KEY AUTO_INCREMENT,
    employee_name VARCHAR(100),
    designation VARCHAR(100),
    salary DECIMAL(10,2),
    contact_number VARCHAR(20)
);

CREATE TABLE Reviews(
    review_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    package_id INT,

    rating INT CHECK(rating BETWEEN 1 AND 5),

    comment TEXT,
    review_date DATE,

    FOREIGN KEY(user_id)
    REFERENCES Users(user_id),

    FOREIGN KEY(package_id)
    REFERENCES TourPackages(package_id)
);

CREATE TABLE Coupons(
    coupon_id INT PRIMARY KEY AUTO_INCREMENT,
    coupon_code VARCHAR(50),
    discount_percent INT,
    expiry_date DATE
);

CREATE TABLE Wishlist(
    wishlist_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    package_id INT,

    FOREIGN KEY(user_id)
    REFERENCES Users(user_id),

    FOREIGN KEY(package_id)
    REFERENCES TourPackages(package_id)
);

CREATE TABLE Notifications(
    notification_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    message TEXT,
    status VARCHAR(20),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY(user_id)
    REFERENCES Users(user_id)
);

CREATE TABLE TourGuides(
    guide_id INT PRIMARY KEY AUTO_INCREMENT,
    guide_name VARCHAR(100),
    language_spoken VARCHAR(100),
    experience_years INT,
    phone VARCHAR(20)
);

CREATE TABLE PackageGuide(
    pg_id INT PRIMARY KEY AUTO_INCREMENT,
    package_id INT,
    guide_id INT,

    FOREIGN KEY(package_id)
    REFERENCES TourPackages(package_id),

    FOREIGN KEY(guide_id)
    REFERENCES TourGuides(guide_id)
);

CREATE TABLE EmergencyContacts(
    emergency_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    contact_name VARCHAR(100),
    relation_person VARCHAR(50),
    phone VARCHAR(20),

    FOREIGN KEY(user_id)
    REFERENCES Users(user_id)
);

CREATE TABLE Insurance(
    insurance_id INT PRIMARY KEY AUTO_INCREMENT,
    booking_id INT,
    provider_name VARCHAR(100),
    insurance_amount DECIMAL(10,2),

    FOREIGN KEY(booking_id)
    REFERENCES Bookings(booking_id)
);

CREATE TABLE Expenses(
    expense_id INT PRIMARY KEY AUTO_INCREMENT,
    expense_type VARCHAR(100),
    amount DECIMAL(10,2),
    expense_date DATE,
    description TEXT
);

CREATE TABLE Activities(
    activity_id INT PRIMARY KEY AUTO_INCREMENT,
    activity_name VARCHAR(100),
    activity_cost DECIMAL(10,2),
    description TEXT
);

CREATE TABLE PackageActivities(
    pa_id INT PRIMARY KEY AUTO_INCREMENT,
    package_id INT,
    activity_id INT,

    FOREIGN KEY(package_id)
    REFERENCES TourPackages(package_id),

    FOREIGN KEY(activity_id)
    REFERENCES Activities(activity_id)
);

CREATE TABLE Refunds(
    refund_id INT PRIMARY KEY AUTO_INCREMENT,
    booking_id INT,
    refund_amount DECIMAL(10,2),
    refund_date DATE,

    refund_status ENUM(
        'Pending',
        'Completed'
    ),

    FOREIGN KEY(booking_id)
    REFERENCES Bookings(booking_id)
);

CREATE TABLE SupportTickets(
    ticket_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    subject VARCHAR(200),
    message TEXT,

    ticket_status ENUM(
        'Open',
        'Closed',
        'Pending'
    ),

    FOREIGN KEY(user_id)
    REFERENCES Users(user_id)
);

CREATE INDEX idx_destination
ON TourPackages(destination);

CREATE INDEX idx_booking_date
ON Bookings(booking_date);

CREATE VIEW CustomerBookingView AS

SELECT
Users.full_name,
TourPackages.package_name,
Bookings.travel_date,
Bookings.booking_status

FROM Bookings

JOIN Users
ON Bookings.user_id = Users.user_id

JOIN TourPackages
ON Bookings.package_id = TourPackages.package_id;

DELIMITER //

CREATE TRIGGER booking_notification

AFTER INSERT ON Bookings

FOR EACH ROW

BEGIN

INSERT INTO Notifications(
    user_id,
    message,
    status
)

VALUES(
    NEW.user_id,
    'Your booking has been confirmed',
    'Unread'
);

END //

DELIMITER ;

DELIMITER //

CREATE PROCEDURE GetUserBookings(IN uid INT)

BEGIN

SELECT
Bookings.booking_id,
TourPackages.package_name,
Bookings.travel_date

FROM Bookings

JOIN TourPackages
ON Bookings.package_id = TourPackages.package_id

WHERE Bookings.user_id = uid;

END //

DELIMITER ;

INSERT INTO Users(
full_name,
email,
phone,
password,
address,
role
)

VALUES

(
'Admin User',
'admin@gmail.com',
'01800000000',
'admin123',
'Dhaka',
'Admin'
),

(
'Motiur Rahman',
'motiur@gmail.com',
'01711111111',
'12345',
'Chattogram',
'Customer'
);

INSERT INTO Destinations(
destination_name,
country,
description
)

VALUES

(
'Coxs Bazar',
'Bangladesh',
'World Longest Sea Beach'
),

(
'Sajek',
'Bangladesh',
'Beautiful Hill Area'
);

INSERT INTO TourPackages(
package_name,
destination,
duration_days,
price,
max_people,
description,
image_url,
created_by
)

VALUES

(
'Coxs Bazar Tour',
'Coxs Bazar',
5,
15000,
20,
'Sea Beach Tour',
'img1.jpg',
1
),

(
'Sajek Valley Tour',
'Sajek',
3,
10000,
15,
'Hill Track Tour',
'img2.jpg',
1
);

INSERT INTO Bookings(
user_id,
package_id,
booking_date,
travel_date,
total_people,
total_cost,
booking_status
)

VALUES

(
2,
1,
'2026-05-20',
'2026-06-01',
2,
30000,
'Confirmed'
);

INSERT INTO Payments(
booking_id,
payment_method,
amount,
payment_date,
payment_status
)

VALUES

(
1,
'Bkash',
30000,
'2026-05-21',
'Paid'
);

INSERT INTO Reviews(
user_id,
package_id,
rating,
comment,
review_date
)

VALUES

(
2,
1,
5,
'Amazing Coxs Bazar Tour',
'2026-05-22'
),

(
2,
2,
4,
'Beautiful Sajek Experience',
'2026-05-23'
),

(
1,
1,
5,
'Excellent Management',
'2026-05-24'
),

(
1,
2,
4,
'Very Nice Tour',
'2026-05-25'
);

INSERT INTO Hotels(
hotel_name,
location,
rating,
available_rooms,
price_per_night
)

VALUES

(
'Sea View Resort',
'Coxs Bazar',
4.5,
10,
5000
),

(
'Hill Crown Hotel',
'Sajek',
4.2,
8,
3500
);

INSERT INTO Transport(
transport_type,
company_name,
seat_capacity,
departure_time
)

VALUES

(
'Bus',
'Green Line',
40,
'08:00:00'
),

(
'Jeep',
'Sajek Express',
12,
'07:30:00'
);

INSERT INTO TourGuides(
guide_name,
language_spoken,
experience_years,
phone
)

VALUES

(
'Rahim Guide',
'Bangla,English',
5,
'01899999999'
),

(
'Karim Guide',
'Bangla,English',
7,
'01788888888'
);

SELECT
SUM(amount) AS Total_Revenue

FROM Payments

WHERE payment_status='Paid';

SELECT
TourPackages.package_name,

COUNT(Bookings.booking_id)
AS Total_Booking

FROM Bookings

JOIN TourPackages
ON Bookings.package_id =
TourPackages.package_id

GROUP BY TourPackages.package_name

ORDER BY Total_Booking DESC;

SELECT
Users.full_name,
TourPackages.package_name,
Bookings.travel_date

FROM Bookings

JOIN Users
ON Bookings.user_id =
Users.user_id

JOIN TourPackages
ON Bookings.package_id =
TourPackages.package_id;

SELECT
TourPackages.package_name,

AVG(Reviews.rating)
AS Average_Rating

FROM Reviews

JOIN TourPackages
ON Reviews.package_id =
TourPackages.package_id

GROUP BY TourPackages.package_name;

SELECT
Users.full_name,

SUM(Payments.amount)
AS TotalSpent

FROM Payments

JOIN Bookings
ON Payments.booking_id =
Bookings.booking_id

JOIN Users
ON Bookings.user_id =
Users.user_id

GROUP BY Users.full_name

ORDER BY TotalSpent DESC;

SELECT
hotel_name,
available_rooms

FROM Hotels

WHERE available_rooms > 0;

SELECT
package_name,
price

FROM TourPackages

WHERE price >

(
SELECT AVG(price)
FROM TourPackages
);

SELECT
TourPackages.package_name,

COUNT(Reviews.review_id)
AS TotalReviews

FROM Reviews

JOIN TourPackages
ON Reviews.package_id =
TourPackages.package_id

GROUP BY TourPackages.package_name

ORDER BY TotalReviews DESC;

SELECT * FROM Notifications;


CALL GetUserBookings(2);