#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	// write your code here
	double max_value_per_weight;
	int index;
	int n = weights.size();
	while (capacity > 0) {
		max_value_per_weight = 0;
		for (int i = 0; i < n; ++i) {
			if ((double)values[i] / weights[i] > max_value_per_weight) {
				max_value_per_weight = (double)values[i] / weights[i];
				index = i;
			}
		}
		if (max_value_per_weight == 0) {
			break;
		}
		if (capacity >= weights[index]) {
			value += values[index];
			capacity -= weights[index];
		}
		else {
			value += (double)values[index] / weights[index] * capacity;
			capacity = 0;
		}
		values[index] = 0;
	}

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
