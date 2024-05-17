#include <iostream>
#include <vector>
#include <random>
using namespace std;

const int RANGE = 20;
const int MAX_ELEMENTS = 50;

// Utility functions
vector<int> generateRandomVectorOfSize(int size);
void printVector(vector<int>& vec);

// Sorting Algorithms
void shellSort(vector<int>& vec, int& num_comparisons, int& num_items_moved);
void insertionSort(vector<int>& vec, int& num_comparisons, int& num_items_moved);

int main() {
	// Use the current time as a seed for the random generator
	srand(time(0));
	int num_elements = 1;

	while (num_elements != 0) {
		try {
			cout << "+++ Insertion Sort and Shell Sort +++\n\n";
			cout << "Enter the number of elements to be sorted (zero to exit): ";
			cin >> num_elements;

			if (cin.fail()) {
				throw invalid_argument("Invalid input");
			}

			if (num_elements < 0) {
				cout << "Error: Number of elements must be greater than 0\n";
			}
			else if (num_elements > MAX_ELEMENTS) {
				cout << "Error: Number of elements must not exceed " << MAX_ELEMENTS << endl;
			}
			else {
				// Generate a random vector of user specified size
				vector<int> my_vector = generateRandomVectorOfSize(num_elements);
				vector<int> my_vector_copy = my_vector;

				cout << "Test case with " << num_elements << " elements\n";
				cout << "Unsorted array with " << num_elements << " to be sorted:\n";
				printVector(my_vector);

				// Insertion Sort
				int num_comparisons = 0, num_items_moved = 0;
				insertionSort(my_vector, num_comparisons, num_items_moved);

				cout << "\n**Results of Insertion Sort\n";
				cout << "Insertion sort comparisons: " << num_comparisons << endl;
				cout << "Insertion sort number of items moved: " << num_items_moved << endl;

				// Shell Sort
				shellSort(my_vector_copy, num_comparisons, num_items_moved);
				cout << "\n**Results of Shell Sort\n";
				cout << "Insertion sort comparisons: " << num_comparisons << endl;
				cout << "Insertion sort number of items moved: " << num_items_moved << endl;

				// Print vector again
				printVector(my_vector_copy);
			}
		}
		catch (const std::invalid_argument& e) {
			cout << "Error: Invalid Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch (const std::exception& e) {
			cout << "An error occurred: " << e.what() << endl;
		}
	}
	
	cout << "Terminating Program...\n";
	return 0;
}

void shellSort(vector<int>& vec, int& num_comparisons, int& num_items_moved) {
	for (int gap = vec.size() / 2; gap >= 1; gap /= 2) {
		for (int i = gap; i < vec.size(); ++i) {
			int temp = vec[i];
			int j = i;

			while (j >= gap && vec[j - gap] > temp) {
				vec[j] = vec[j - gap];
				j -= gap;

				++num_comparisons;
				++num_items_moved;
			}
			vec[j] = temp;
			++num_items_moved;
		}
	}
}

void insertionSort(vector<int>& vec, int& num_comparisons, int& num_items_moved) {
	// Vectors with only one element are already sorted by definition
	if (vec.size() <= 1) {
		cout << "Containers with only one element are already sorted by definition\n";
	}
	else {
		int i, key, j;
		for (i = 1; i < vec.size(); ++i) {
			key = vec[i]; // Start with the second element in the container
			j = i - 1; // We use j to keep track of the values to the left of our current element

			while (j >= 0 && vec[j] > key) {
				vec[j + 1] = vec[j];
				j = j - 1;

				num_comparisons++;
				num_items_moved++;
			}
			vec[j + 1] = key;
			++num_items_moved;
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
			cout << vec[i];
		}
		else {
			cout << vec[i] << ", ";
		}
	}
	cout << "]\n";
}