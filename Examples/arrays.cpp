// Include libraries
#include <cstdio>

// Common code
void printArray(int* array, int N);
void printMatrix(int** matrix, int N, int M);

// Driver code
int main(int argc, char* argv[]) {

    // Define the input space for 
    // all the following demonstrations
    int N = 3, M = 4;


    ////////////////////////////////////
    //           1D ARRAYS            //
    ////////////////////////////////////


    // Simple array declaration and iteration
    int A[N];
    for (int i = 0; i < N; i++)
        A[i] = i;

    printArray(A, N);

    // Same thing but using the "new" syntax, which
    // is analgous to the C++ version of malloc()
    int* B = new int[N];
    for (int i = 0; i < N; i++)
        B[i] = i;

    printArray(B, N);

    // Single element pointer arithmatic;
    // Accessing B[1], which should be '1'
    printf("%i\n\n", *(B + 1));


    ////////////////////////////////////
    //           2D MATRICES          //
    ////////////////////////////////////

    // Initialize and fill a matrix with the "new"
    // syntax, similar to the example prior
    //
    // NOTE: Just like 2D arrays with malloc() in C, 
    //       we'll have to malloc() each row individually
    //
    int** C = new int*[N];
    for(int i = 0; i < N; i++)
        C[i] = new int[M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            C[i][j] = (i * M) + j;
    }

    printMatrix(C, N, M);

    // Mathmatical way of accessing all
    // elements inside of a single loop
    for (int i = 0; i < (N * M); i++)
        printf("%i%s", C[i / M][i % M], 
            (i + 1) % M == 0? "\n":", ");

    printf("\n");

    // Pointer arithmatic for equivalent access of C[2][3]; 
    // First, reference the start of the 3rd row with "C[2]" 
    // and then go over 3 columns by adding '3' to it
    printf("%i\n\n", *(C[2] + 3));

    // Printing the first element of each row looks like this
    // with just one for-loop and using pointer arithmatic
    //
    // NOTE: There's some special math going on to calculate
    //       what we're accessing. It works by accessing the start
    //       of the C matrix, adding however many rows down we are
    //       multiplied by how many columns it takes to get there
    //
    for (int i = 0; i < N; i++)
        printf("%i%s", *(C + ((i + 1) * M)),
                i == N - 1? "\n":", ");

    printf("\n");

    return 0;
}

void printArray(int* array, int N) {
    for (int i = 0; i < N; i++)
        printf("%i%s", array[i], i == N - 1? "\n":", ");

    printf("\n");
}

void printMatrix(int** matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%i%s", matrix[i][j], j == M - 1? "\n":", ");
    }

    printf("\n");
}