class Solution {
public:
    int nthUglyNumber(int n) {
        // Min heap to store ugly numbers in ascending order
        priority_queue<long, vector<long>, greater<long>> minHeap;
      
        // Set to track visited numbers and avoid duplicates
        unordered_set<long> visited{{1L}};
      
        // Start with the first ugly number
        minHeap.push(1L);
      
        // Variable to store the current ugly number
        long currentUglyNumber = 1;
      
        // Prime factors that define ugly numbers
        vector<int> primeFactors = {2, 3, 5};
      
        // Process n ugly numbers
        while (n--) {
            // Extract the smallest ugly number from the heap
            currentUglyNumber = minHeap.top();
            minHeap.pop();
          
            // Generate new ugly numbers by multiplying with prime factors
            for (int& prime : primeFactors) {
                long nextUglyNumber = currentUglyNumber * prime;
              
                // Add to heap only if not already visited
                if (!visited.count(nextUglyNumber)) {
                    visited.insert(nextUglyNumber);
                    minHeap.push(nextUglyNumber);
                }
            }
        }
      
        // Return the nth ugly number
        return static_cast<int>(currentUglyNumber);
    }
};
