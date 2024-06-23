// Printing statements
#include <cstdio>

// Random number generation
#include <random>

// Basic functionality
int check(int array[], int N);
void randomization(int array[], int N);

// Sorting methods
void selectionSort(int array[], int N);
void insertionSort(int array[], int N);
void bubbleSort(int array[], int N);
void quickSort(int array[], int N);
void mergeSort(int array[], int N);

// Driver
int main(int argc, char* argv[]) {

    // Define the input and perform
    // whatever preprocessing we need
    // (e.g. some randomization, etc.)
    int input[5];
    int N = sizeof(input)/sizeof(*input);
    randomization(input, N);

    // Print the input array
    for (int i = 0; i < N; i++)
        printf("%i%s", input[i], i == (N-1)? "\n\n":", ");

    // Perform the desired sorting method
    selectionSort(input, N);

    // Check the final product and print the results
    printf("%s\n", check(input, N)? "Failed":"Passed");

    for (int i = 0; i < N; i++)
        printf("%i%s", input[i], i == (N-1)? "\n":", ");

    return 0;
}

/*
    Validate a given 'array' of size 'N' 
    by iterating through the values [1..N]
    and confirming each value is not smaller
    than the previous value
*/
int check(int array[], int N) {

    // Early return conditions
    if (N == 0 || N == 1)
        return 0;

    // Iterate through the array[1..N]
    for (int i = 1; i < N; i++) {

        // If at the current index 'i' 
        // the value is unsorted, return '1'
        if (array[i] < array[i - 1])
            return 1;
    }

    // All values came out sorted,
    // return a successful '0' value
    return 0;
}

/*
    Assing random values to the elements
    a given 'array' of size 'N'
*/
void randomization(int array[], int N) {
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100);

    // For every element at position 'i'
    // of array[0..N], assign a random value
    for (int i = 0; i < N; i++)
        array[i] = dist6(rng);
}

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

void insertionSort(int array[], int N) {
    // TODO
}

void bubbleSort(int array[], int N) {

    // Early return conditions
    if (N == 0 || N == 1)
        return;

    // Initialize a 'flag' variable and
    // something to hold temporary values
    int flag = 1, temporary = 0;
    
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
                temporary = array[i - 1];
                array[i -1] = array[i];
                array[i] = temporary;
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

void quickSort(int array[], int N) {
    // TODO
}

void mergeSort(int array[], int N) {
    // TODO
}