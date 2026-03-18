Create database Students; 
use Students;
CREATE TABLE Students (
    ID INT PRIMARY KEY,
    Name VARCHAR(50),
    CGPA DECIMAL(3, 2),
    Department VARCHAR(20)
);


INSERT INTO Students VALUES (101, 'Rahim', 3.80, 'CSE');
INSERT INTO Students VALUES (102, 'Karim', 3.40, 'EEE');
INSERT INTO Students VALUES (103, 'Abir', 1.90, 'BBA');


SELECT * FROM Students WHERE CGPA > 3.50;


UPDATE Students SET Name = 'Shuvo' WHERE ID = 102;


DELETE FROM Students WHERE CGPA < 2.00;
