Create database Mystaff; 
use Mystaff; 

create table staff (  
staffid int primary key, 
Name varchar(30), 
Designation varchar(30), 
Salary decimal(10, 5), 
Joinyear int 
); 

Insert into staff values(1, 'motiur', 'manager', 300.00, 2000); 
Insert into staff values(2, 'shuvo', 'developer', 400.00, 2002); 
Insert into staff values(3, 'rahman', 'designer', 500.00, 2003); 
Insert into staff values(4, 'rihan', 'intern', 600.00, 2009);
  
  Select * from staff where Designation = 'developer'; 
  
  Select  name from staff where salary > 400.00; 
   
   Delete from staff where staffid = 4;
  
 
