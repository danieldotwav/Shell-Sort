#include <iostream>
#include <array>
#include <vector>
#include <random>
using namespace std;

const int SMALL = 15;
const int LARGE = 50;
const int RANGE = 20;

// Utility functions
vector<int> generateRandomVectorOfSize(int size);
void printVector(vector<int>& vec);

// Sorting Algorithms
void shellSort(vector<int>& vec, int num_comparisons, int num_items_moved);
//void insertionSort(vector<int>& vec, int num_comparisons, int num_items_moved);

int main() {
	// Use the current time as a seed for the random generator
	srand(time(0));

	// Generate a random vector of size 15
	vector<int> my_vector = generateRandomVectorOfSize(20);
	vector<int> my_vector_copy = my_vector;

	// Print vector
	printVector(my_vector);

	// Shell Sort
	shellSort(my_vector, 0, 0);

	// Print vector again
	printVector(my_vector);

	return 0;
}

void shellSort(vector<int>& vec, int num_comparisons, int num_items_moved) {
	for (int gap = vec.size() / 2; gap >= 1; gap /= 2) {
		for (int i = gap; i < vec.size(); ++i) {
			int temp = vec[i];
			int j = i;

			while (j >= gap && vec[j - gap] > temp) {
				vec[j] = vec[j - gap];
				j -= gap;
			}
			vec[j] = temp;
		}
	}
}

vector<int> generateRandomVectorOfSize(int size) {
	vector<int> vec;
	for (int i = 0; i < size; ++i) {
		vec.push_back(rand() % 20);
	}
	return vec;
}

void printVector(vector<int>& vec) {
	cout << "[";
	for (int i = 0; i < vec.size(); ++i) {
		if (i == vec.size() - 1) {
			cout << vec[i] << "]";
		}
		else {
			cout << vec[i] << ", ";
		}
	}
	cout << endl;
}