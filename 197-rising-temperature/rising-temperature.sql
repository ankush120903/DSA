-- Write your PostgreSQL query statement below
SELECT today.id
from Weather as today
WHERE EXISTS

   (select 1 from weather as yesterday
   where yesterday.temperature < today.temperature
   and
   today.recorddate - yesterday.recorddate = 1)

