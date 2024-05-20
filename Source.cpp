#include "Sort.h"
#include "Utility.h"
using namespace std;

int main() {
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
			else if (num_elements == 0) {
				cout << "Terminating Program...";
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
				num_comparisons = 0, num_items_moved = 0;
				shellSort(my_vector_copy, num_comparisons, num_items_moved);
				cout << "\n**Results of Shell Sort\n";
				cout << "Insertion sort comparisons: " << num_comparisons << endl;
				cout << "Insertion sort number of items moved: " << num_items_moved << endl;

				// Print vector again
				printVector(my_vector_copy);

				cout << endl;
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

	return 0;
}
