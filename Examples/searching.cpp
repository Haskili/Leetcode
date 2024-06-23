// Printing statements
#include <cstdio>

// Random number generation
#include <random>

// Basic functionality
int randomization(int array[], int N);
void selectionSort(int array[], int N);

// Searching functions
int binarySearch(int array[], int target, int L, int R);

// Driver function
int main (int argc, char* argv[]) {
    
    // Define the input and perform
    // whatever preprocessing we need
    // (e.g. some randomization, etc.)
    int input[5];
    int N = sizeof(input)/sizeof(*input);
    int M = randomization(input, N);

    // Display the final input
    printf("Input Array: (Seeking '%i')\n", M);
    for (int i = 0; i < N; i++)
        printf("%i%s", input[i], i == N - 1? "\n\n":", ");

    // Perform a type of searching for the target 'M'
    int answer = binarySearch(input, M, 0, N);

    // Check the result for accuracy and print to terminal
    if (answer < 0)
        printf("Value '%i' not found in the array!\n", M);

    else if (input[answer] != M)
        printf("Incorrect value at answer of '%i', looking for '%i'\n", 
            input[answer], M);

    else
        printf("Value of '%i' found at position '%i'\n", M, answer);
}

/*
    Assing random values to the elements
    a given 'array' of size 'N' and return
    back a random number within 'array'
*/
int randomization(int array[], int N) {
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> P1(1, 100);

    // For every element at position 'i'
    // of array[0..N], assign a random value
    for (int i = 0; i < N; i++)
        array[i] = P1(rng);

    // Sort the input 'array' so that certain searches can work
    selectionSort(array, N);

    // Return a random value from within 'array'
    std::uniform_int_distribution<std::mt19937::result_type> P2(0, N);
    return array[P2(rng)];
}

/*
    Perform basic sorting to make certain types
    of searching possible (e.g. binary)
*/
void selectionSort(int array[], int N) {

    // Early return conditions
    if (N == 0 || N == 1)
        return;

    // For every element in 'array' [0..N]
    for (int i = 0, temporary = 0; i < N; i++) {

        // Find the index of minimum value element
        // in the subarray array[i..N]
        int minimum = i;
        for (int j = (i + 1); j < N; j++) {
            if (array[j] < array[minimum])
                minimum = j;
        }
        
        // If we found a new minimum value,
        // swap the values at the 'minimum'
        // and the current position 'i'
        if (minimum != i) {
            temporary = array[i];
            array[i] = array[minimum];
            array[minimum] = temporary;
        }
    }
}

/*
    Perform basic binary search
*/
int binarySearch(int array[], int target, int L, int R) {

    // Get the midpoint 'M'
    int M = (L + R) / 2;

    // Check if the value at the midpoint is the 'target'
    if (array[M] == target)
        return M;
    
    // Check if the value at the right side is the 'target'
    else if (array[R] == target)
        return R;

    // Check if the value at the right side is the 'target'
    else if (array[L] == target)
        return L;

    // If at this point our search window size is less than
    // 2 and nothing inside that window was the 'target',
    // we can determine it isn't inside the given array
    if ((R - L) <= 1)
        return -1;

    // If the value at the midpoint is
    // GREATER than the target, then
    // search the left hand portion array[L..M]
    if (array[M] > target)
        return binarySearch(array, target, L, M);

    // Otherwise, search in the opposite direction
    // array[M..R]
    else
        return binarySearch(array, target, M, R);
}