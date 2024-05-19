#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <random>

const int RANGE = 20;
const int MAX_ELEMENTS = 50;

// Sorting Algorithms
void shellSort(std::vector<int>& vec, int& num_comparisons, int& num_items_moved) {
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

void insertionSort(std::vector<int>& vec, int& num_comparisons, int& num_items_moved) {
	// Vectors with only one element are already sorted by definition
	if (vec.size() <= 1) {
		std::cout << "Containers with only one element are already sorted by definition\n";
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

#endif