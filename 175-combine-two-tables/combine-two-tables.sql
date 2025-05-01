# Write your MySQL query statement below
Select firstName, lastName, city, state From Person left JOIN Address on Person.personId = Address.personId;