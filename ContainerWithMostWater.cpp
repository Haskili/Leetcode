/*
    This is a simple two-pointer type solution to the problem,
    where we have pointers increment or decrement based on which
    is at a higher value of 'height' at the end of any give iteration.

    Runtime: 51ms (Beats 93.10% of users with C++)
    Memory: 61.34mb (Beats 64.72% of users with C++)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {

        // Define the problem space 'N'
        int N = (int)height.size();

        // Initialize a left and right index pointer
        int L = 0, R = N - 1;

        // Initialize values for tracking areas
        int maximum = 0;
        int current = 0;

        // While our left pointer hasn't yet encountered the right pointer
        while (L < R) {

            // Calculate the current area and conditionally set 'maximum'
            maximum = max(maximum, min(height[L], height[R]) * (R - L));

            // Alter either pointer based on which is higher
            if (height[L] < height[R])
                L++;
            else
                R--;
        }

        // Return the conclusion
        return maximum;
    }
};
