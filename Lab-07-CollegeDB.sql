
CREATE DATABASE CollegeDB;
USE CollegeDB;


CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    Department VARCHAR(50),
    CGPA DECIMAL(3,2),
    AdmissionDate DATE
);


INSERT INTO Students VALUES (1, 'Rahim', 'CSE', 3.75, '2023-01-10');
INSERT INTO Students VALUES (2, 'Karim', 'EEE', 3.20, '2023-02-15');
INSERT INTO Students VALUES (3, 'Sakib', 'CSE', 3.90, '2023-03-20');
INSERT INTO Students VALUES (4, 'Nabil', 'BBA', 2.80, '2023-04-25');


SELECT * FROM Students WHERE CGPA > 3.50;


SELECT Name, Department FROM Students;


UPDATE Students
SET CGPA = 3.80
WHERE StudentID = 2;


DELETE FROM Students WHERE CGPA < 3.00;
