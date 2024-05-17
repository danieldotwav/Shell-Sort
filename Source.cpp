#include <iostream>
#include <array>
#include <random>
using namespace std;

const int SMALL = 15;
const int LARGE = 50;
const int RANGE = 20;

// Utility functions
int* generateRandomArrayOfSize(int size);
void printArray(int* a, int size);

// Sorting Algorithms
void shellSort(int* a, int size, int num_comparisons, int num_items_moved);

int main() {
	// Use the current time as a seed for the random generator
	srand(time(0));

	// Generate a random array of size 15
	int* my_arr = generateRandomArrayOfSize(15);

	// Print array to verify randomness
	printArray(my_arr, 15);

    // Free up dynamically allocated memory
    delete[] my_arr;

	return 0;
}

void shellSort(int* a, int size, int num_comparisons, int num_items_moved) {

}

// This function takes in 
int* generateRandomArrayOfSize(int size) {
    if (size == SMALL) {
        // Dynamically allocate an array of size 15
        int* arr = new int[SMALL];

        // Generate 15 random values between 0 and 20
        for (int i = 0; i < SMALL; ++i) {
            arr[i] = rand() % RANGE;
        }

        return arr;
    }
    else if (size == LARGE) {
        // Dynamically allocate an array of size 50
        int* arr = new int[LARGE];

        // Generate 50 random values between 0 and 20
        for (int i = 0; i < LARGE; ++i) {
            arr[i] = rand() % RANGE;
        }

        return arr;
    }
    else {
        cout << "Error: Unable to determine array size. Function parameter should be either SMALL or LARGE." << endl;
        return nullptr;
    }
}

void printArray(int* a, int size) {
	cout << "[";
	for (int i = 0; i < size; ++i) {
		if (i == size - 1) {
			cout << a[i] << "]";
		}
		else {
			cout << a[i] << ", ";
		}
	}
}