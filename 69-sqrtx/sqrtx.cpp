class Solution {
public:
    int mySqrt(int x) {
        // Handle edge case
        if (x == 0) {
            return 0;
        }

        int left = 1;
        int right = x;
        int firstTrueIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Feasible: mid * mid > x (using division to avoid overflow)
            if (mid > x / mid) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // If firstTrueIndex is -1, no value has mid * mid > x
        // This happens when x <= 1, return x
        if (firstTrueIndex == -1) {
            return x;
        }
        return firstTrueIndex - 1;
    }
};
