Create database UniversityDB; 
use UniversityDB; 

 Create table Students ( 
 StudentID int primary key, 
 Name varchar(40), 
 Department varchar(50), 
 CGPA decimal(10, 2) 
 ); 
  
  Insert into Students values(1,'motiur','CSE',3.80); 
   Insert into Students values(2,'shuvo','EEE',3.85); 
    Insert into Students values(3,'rihan','ETE',3.90); 
     Insert into Students values(4,'farhan','English',3.81); 
      Insert into Students values(5,'trisha','CSE',3.85); 
      
Select * from Students; 

Select * from Students where CGPA > 3.50;  

Update Students 
Set CGPA = 3.85
Where StudentID = 3; 

Delete from Students Where StudentID = 2; 

Select * from Students; 

Select * from Students where Department = 'CSE'; 



