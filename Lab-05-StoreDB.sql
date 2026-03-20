
CREATE DATABASE StoreDB;
USE StoreDB;


CREATE TABLE Sales (
    SaleID INT PRIMARY KEY,
    CustomerName VARCHAR(50),
    ProductName VARCHAR(50),
    Category VARCHAR(30),
    Price DECIMAL(10,2),
    Quantity INT,
    SaleDate DATE
);


INSERT INTO Sales VALUES (1, 'Rahim', 'Laptop', 'Electronics', 60000.00, 1, '2026-03-01');
INSERT INTO Sales VALUES (2, 'Karim', 'Mouse', 'Accessories', 500.00, 3, '2026-03-02');
INSERT INTO Sales VALUES (3, 'Sakib', 'Keyboard', 'Accessories', 1500.00, 2, '2026-03-03');
INSERT INTO Sales VALUES (4, 'Nabil', 'PhoneDB', 'Electronics', 20000.00, 1, '2026-03-04');
INSERT INTO Sales VALUES (5, 'Fahim', 'Monitor', 'Electronics', 12000.00, 2, '2026-03-05');


SELECT * FROM Sales WHERE Category = 'Electronics';


SELECT *, (Price * Quantity) AS TotalCost FROM Sales;


SELECT * FROM Sales WHERE Quantity > 2;


UPDATE Sales
SET Price = Price * 1.10
WHERE Category = 'Accessories';


DELETE FROM Sales
WHERE (Price * Quantity) < 1000;

SELECT * FROM Sales ORDER BY Price DESC;


SELECT DISTINCT Category FROM Sales;
