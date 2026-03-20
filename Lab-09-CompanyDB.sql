
CREATE DATABASE CompanyDB;
USE CompanyDB;


CREATE TABLE Employees (
    EmpID INT PRIMARY KEY,
    Name VARCHAR(50),
    Department VARCHAR(50),
    Salary DECIMAL(10,2)
);


INSERT INTO Employees VALUES (1, 'Rahim', 'HR', 15000.00);
INSERT INTO Employees VALUES (2, 'Karim', 'IT', 25000.00);
INSERT INTO Employees VALUES (3, 'Sakib', 'IT', 30000.00);
INSERT INTO Employees VALUES (4, 'Nabil', 'Finance', 12000.00);
INSERT INTO Employees VALUES (5, 'Fahim', 'HR', 18000.00);


SELECT MAX(Salary) AS HighestSalary FROM Employees;


SELECT AVG(Salary) AS AverageSalary FROM Employees;


SELECT COUNT(*) AS TotalEmployees FROM Employees;


SELECT Department, COUNT(*) AS TotalEmployees
FROM Employees
GROUP BY Department;


SELECT Department, SUM(Salary) AS TotalSalary
FROM Employees
GROUP BY Department;


DELETE FROM Employees WHERE Salary < 10000;
