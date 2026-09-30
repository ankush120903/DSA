-- Write your PostgreSQL query statement below
select customer_id, COUNT(*) as count_no_trans
from Visits as v
LEFT JOIN
Transactions as t
ON
v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY customer_id