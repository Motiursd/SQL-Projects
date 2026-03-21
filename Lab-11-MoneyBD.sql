CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    Name VARCHAR(50),
    City VARCHAR(50)
);

CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerID INT,
    Product VARCHAR(50),
    Amount DECIMAL(10,2),
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

INSERT INTO Customers VALUES
(1, 'Rahim', 'Dhaka'),
(2, 'Karim', 'Chittagong'),
(3, 'Sakib', 'Dhaka'),
(4, 'Nayeem', 'Sylhet'),
(5, 'Motiur', 'Chittagong');

INSERT INTO Orders VALUES
(101,1,'Laptop',700),
(102,2,'Phone',300),
(103,3,'Tablet',600),
(104,1,'Mouse',50),
(105,5,'Keyboard',200);


SELECT Customers.Name, Orders.Product
FROM Customers
JOIN Orders ON Customers.CustomerID = Orders.CustomerID;


SELECT * FROM Orders WHERE Amount > 500;


SELECT CustomerID, SUM(Amount) AS Total
FROM Orders
GROUP BY CustomerID;
