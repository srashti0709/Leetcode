# Write your MySQL query statement below
Select e.name, b.bonus
From Employee e
LEFT JOIN Bonus b
on e.empId = b.empId 
WHERE bonus IS NULL or bonus < 1000;