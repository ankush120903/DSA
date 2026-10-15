class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
      
        // Iterate through all possible starting positions of subarrays
        for (int i = 0; i < n; ++i) {
            // Frequency array to track occurrences of each element (assumes values are in range [0, 100])
            int frequency[101] = {0};
            int distinctCount = 0;
          
            // Extend the subarray from position i to the end
            for (int j = i; j < n; ++j) {
                // Increment frequency of current element
                // If this is the first occurrence (frequency becomes 1), increment distinct count
                if (++frequency[nums[j]] == 1) {
                    ++distinctCount;
                }
              
                // Add the square of distinct count to the total sum
                totalSum += distinctCount * distinctCount;
            }
        }
      
        return totalSum;
    }
};
