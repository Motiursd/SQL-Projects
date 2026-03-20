
CREATE DATABASE LibraryDB;
USE LibraryDB;


CREATE TABLE Books (
    BookID INT PRIMARY KEY,
    Title VARCHAR(50),
    Author VARCHAR(50),
    Price DECIMAL(10,2),
    Quantity INT
);


INSERT INTO Books VALUES (1, 'C Programming', 'Dennis Ritchie', 450.00, 5);
INSERT INTO Books VALUES (2, 'Database Systems', 'Elmasri', 750.00, 2);
INSERT INTO Books VALUES (3, 'Operating System', 'Galvin', 650.00, 3);
INSERT INTO Books VALUES (4, 'Computer Networks', 'Tanenbaum', 550.00, 1);
INSERT INTO Books VALUES (5, 'Data Structures', 'Mark Allen', 400.00, 4);


SELECT * FROM Books WHERE Price > 500;


SELECT *, (Price * Quantity) AS TotalValue FROM Books;


SELECT * FROM Books WHERE Quantity < 3;


UPDATE Books
SET Price = Price * 1.20
WHERE Quantity < 5;


SELECT * FROM Books ORDER BY Price ASC;
