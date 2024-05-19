#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <random>
#include <iostream>

std::vector<int> generateRandomVectorOfSize(int size) {
	std::vector<int> vec;
	for (int i = 0; i < size; ++i) {
		vec.push_back(rand() % 20);
	}
	return vec;
}

void printVector(std::vector<int>& vec) {
	std::cout << "[";
	for (int i = 0; i < vec.size(); ++i) {
		if (i == vec.size() - 1) {
			std::cout << vec[i];
		}
		else {
			std::cout << vec[i] << ", ";
		}
	}
	std::cout << "]\n";
}

#endif