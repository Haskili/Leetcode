/*
    The following is a basic hashmap type solution that
    relies on storing values along with an index to find
    the answer;

    It iterates through 'numbers', and for each iteration
    it asks if there's a value already in 'mapping' for it.
    If there is, it means we've previously encountered a
    number where all it needed to add up to 'target' was
    the current number. Using that, we return the current
    index along with whatever index is stored for that value.

    Runtime: 6ms (Beats 88.88% of users with C++)
    Memory: 11.54mb (Beats 99.98% of users with C++)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Initialize a container for holding values we've
        // seen and where we've seen them at
        map<int, int> mapping;

        // For each index 'i' in the vector 'numbers'
        for (int i = 0; i < (int)numbers.size(); i++) {

            // If the value at 'numbers[i]' is insite our
            // mapping, then return our current index
            // along with the value at 'numbers[i]'
            if (mapping.find(numbers[i]) != mapping.end())
                return {mapping[numbers[i]], i};

            // Otherwise, store the value of the
            // 'target' subtracted by the current
            // value at 'i' so that if we encounter
            // the number later on to finish it we'll
            // be able to return this index
            mapping[target - numbers[i]] = i;
        }

        return {0, 0};
    }
};
