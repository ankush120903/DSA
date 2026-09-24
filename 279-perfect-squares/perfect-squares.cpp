class Solution {
public:
    int numSquares(int n) {
        // Calculate the maximum perfect square we need to consider
        int maxSquare = sqrt(n);
      
        // dp[i][j] represents the minimum number of perfect squares needed to sum to j
        // using perfect squares from 1^2 to i^2
        int dp[maxSquare + 1][n + 1];
      
        // Initialize all values to a large number (infinity)
        memset(dp, 0x3f, sizeof(dp));
      
        // Base case: 0 perfect squares sum to 0
        dp[0][0] = 0;
      
        // Iterate through each perfect square from 1^2 to maxSquare^2
        for (int i = 1; i <= maxSquare; ++i) {
            // For each target sum from 0 to n
            for (int j = 0; j <= n; ++j) {
                // Option 1: Don't use the current perfect square i^2
                dp[i][j] = dp[i - 1][j];
              
                // Option 2: Use the current perfect square i^2 if possible
                if (j >= i * i) {
                    // Take minimum between not using i^2 and using i^2
                    dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
                }
            }
        }
      
        // Return the minimum number of perfect squares that sum to n
        return dp[maxSquare][n];
    }
};
