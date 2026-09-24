class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
      
        // dp[i][j] represents the number of ways to form sum j using numbers from 1 to i
        // where each number k contributes k^x to the sum
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
      
        // Base case: there's one way to form sum 0 using no numbers
        dp[0][0] = 1;
      
        // Iterate through each number from 1 to n
        for (int currentNumber = 1; currentNumber <= n; ++currentNumber) {
            // Calculate the x-th power of the current number
            long long powerValue = static_cast<long long>(pow(currentNumber, x));
          
            // For each possible sum from 0 to n
            for (int targetSum = 0; targetSum <= n; ++targetSum) {
                // Option 1: Don't include the current number
                dp[currentNumber][targetSum] = dp[currentNumber - 1][targetSum];
              
                // Option 2: Include the current number if its power doesn't exceed the target sum
                if (powerValue <= targetSum) {
                    dp[currentNumber][targetSum] = (dp[currentNumber][targetSum] + 
                                                   dp[currentNumber - 1][targetSum - powerValue]) % MOD;
                }
            }
        }
      
        // Return the number of ways to form sum n using numbers from 1 to n
        return dp[n][n];
    }
};
