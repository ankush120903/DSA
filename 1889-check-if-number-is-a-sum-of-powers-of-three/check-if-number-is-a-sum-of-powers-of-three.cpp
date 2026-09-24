class Solution {
public:
    bool checkPowersOfThree(int n) {
        // Check if n can be represented as a sum of distinct powers of 3
        // Algorithm: Convert n to base-3 representation
        // If all digits in base-3 are 0 or 1, then n is a sum of distinct powers of 3
        // If any digit is 2 or greater, we're using the same power of 3 multiple times
      
        while (n > 0) {
            // Get the remainder when dividing by 3 (current digit in base-3)
            int remainder = n % 3;
          
            // If remainder is greater than 1, it means we need to use 
            // the same power of 3 multiple times, which violates the constraint
            if (remainder > 1) {
                return false;
            }
          
            // Move to the next digit in base-3 representation
            n /= 3;
        }
      
        // All digits in base-3 representation are 0 or 1
        // Therefore, n can be represented as sum of distinct powers of 3
        return true;
    }
};
