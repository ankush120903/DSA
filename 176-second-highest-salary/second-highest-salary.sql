-- Write your PostgreSQL query statement below

SELECT
    (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET 1 --offset 1 means skip the first row
    ) AS SecondHighestSalary;