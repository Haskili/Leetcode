/*
    The following is a minimalist memoization type solution
    to a problem that can otherwise be solved in numerable ways.
    
    The key is simply to use a frequency map in the form of an array,
    which we can do because we know the constraints of the problem
    say that we'll only ever encounter lowercase English characters.
    With that said, we can just use an array and an offset for the
    ASCII characters to increment the characters during iteration
    through one of the strings, and decrement them in iteration of
    the other string.

    At the end, if they're anagrams then the letters should be
    encountered the same amount of times, and thus be '0' in
    the frequency map.

    Runtime: 3ms (Beats 97.04% of users with C++)
    Memory: 8.60mb (Beats 45.02% of users with C++)
*/
class Solution {
public:
    bool isAnagram(string A, string B) {

        // Early exit condition
        if (A.size() != B.size())
            return false;

        // Initialize a container to hold values
        // for frequency of characters in both
        // 'A' & 'B'; Use an offset of '97' for 
        // accessing any given frequency value
        int mapping[26] = {0};

        // Iterate through each position 'i' of 'A',
        // for each character at a given position 'i' 
        // increment the corresponding value in 'mapping'
        for (size_t i = (size_t)0; i < A.size(); i++)
            mapping[A[i] - 97]++;

        // Iterate through each position 'i' of 'B',
        // for each character at a given position 'i' 
        // decrement the corresponding value in 'mapping' 
        for (size_t i = (size_t)0; i < B.size(); i++)
            mapping[B[i] - 97]--;
        
        // Iterate through each position 'i' of 'mapping',
        // if any element at 'i' has a non-zero value then return false
        for (unsigned int i = 0; i < 26; i++)
            if (mapping[i])
                return false;

        return true;
    }
};