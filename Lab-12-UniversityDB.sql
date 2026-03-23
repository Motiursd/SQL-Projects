CREATE DATABASE UniversityDB;

USE UniversityDB;

CREATE TABLE Students(
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    Department VARCHAR(50),
    CGPA DECIMAL(3,2)
);

INSERT INTO Students VALUES
(1,'Rahim','CSE',3.80),
(2,'Karim','EEE',3.20),
(3,'Sakib','BBA',3.60),
(4,'Nayeem','CSE',3.40),
(5,'Motiur','CSE',3.90);

SELECT * FROM Students;

SELECT * FROM Students
WHERE CGPA > 3.50;
