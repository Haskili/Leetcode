/*
    The following is a bubble sort, nothing special.
    It's an O(N^2) average time complexity sorting aglortihm.

    The original implementation I took this from was from some
    old C code that I wrote for another project, so there's even 
    a XOR swap for the "bubbling" part to save memory. Interestingly, 
    the memory still fluctuates between ~30% & ~99% percent users beat
    on memory usage.

    Runtime: 0ms (Beats 100% of users with C++)
    Memory: 9.74mb (Beats 71.60% of users with C++)
*/
void bubbleSort(vector<int>& array) {

    // Define the problem space 'N'
    int N = (int)array.size();

    // Early return conditions
    if (N == 0 || N == 1)
        return;

    // Initialize a 'flag' variable
    int flag = 1;

    // Continue iteration until something
    // inside our loop breaks us out
    while (true) {

        // Iterate through the array[0..N],
        // swapping out the values 'i - 1' & 'i'
        // for any given point 'i' if needed
        for (int i = 1; i < N; i++) {

            // If we need to perform a swap,
            // do so and toggle off the 'flag'
            if (array[i - 1] > array[i]) {
                array[i] ^= array[i - 1], 
                array[i - 1] ^= array[i], 
                array[i] ^= array[i - 1];
                flag = 0;
            }
        }

        // If we performed a full sweep
        // of 'array' and no swaps were
        // needed, we can exit out
        if (flag == 1)
            return;

        // Otherwise, reset the flag
        flag = 1;
    }
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        bubbleSort(nums);
    }
};
