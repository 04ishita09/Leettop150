class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;

        int low = 1, high = x;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;

            if (val == x) {
                return mid;
            } else if (val < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high; // Return the floor of the square root
    }
};