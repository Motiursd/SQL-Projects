CREATE DATABASE ShopDB;
USE ShopDB;

CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerName VARCHAR(50),
    Product VARCHAR(30),
    Price DECIMAL(10,2),
    Quantity INT,
    OrderDate DATE
);

INSERT INTO Orders VALUES (1, 'Tanvir', 'Mouse', 500.00, 2, '2026-03-01');
INSERT INTO Orders VALUES (2, 'Sajid', 'Keyboard', 1200.00, 1, '2026-03-05');
INSERT INTO Orders VALUES (3, 'Akib', 'Monitor', 8500.00, 1, '2026-03-10');
INSERT INTO Orders VALUES (4, 'Rahat', 'USB Hub', 300.00, 3, '2026-03-15');

SELECT * FROM Orders;

SELECT * FROM Orders WHERE Price > 1000;

SELECT Product, Price FROM Orders WHERE CustomerName = 'Akib';

UPDATE Orders
SET Product = 'Webcam', Price = 2000
WHERE OrderID = 1;

DELETE FROM Orders WHERE Price < 500;
