CREATE DATABASE Salesdb;
USE Salesdb;

CREATE TABLE Customers ( 
Customersid INT PRIMARY KEY, 
Name VARCHAR(50), 
City VARCHAR(50), 
Product VARCHAR(30), 
Amount DECIMAL(20, 2), 
Purchasedate DATE 
); 

INSERT INTO Customers VALUES (1,'motiur','chittagong','mouse',100.00,'2026-03-20'); 
INSERT INTO Customers VALUES (2,'shuvo','rajshahi','keyboard',200.00,'2026-03-21'); 
INSERT INTO Customers VALUES (3,'tarik','dhaka','button',400.00,'2026-03-22');
INSERT INTO Customers VALUES (4,'faisal','chittagong','mouse',500.00,'2026-03-23'); 

SELECT * FROM Customers; 

SELECT * FROM Customers WHERE Amount > 200;  

SELECT Name, Product FROM Customers WHERE City = 'dhaka'; 

UPDATE Customers 
SET Product ='mouse', Amount = 300.00 
WHERE Customersid = 2;  

DELETE FROM Customers WHERE Amount < 250;

SELECT * FROM Customers;
