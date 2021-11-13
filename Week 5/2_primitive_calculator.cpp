#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> greedy_optimal_sequence(int n) {
	std::vector<int> sequence;
	while (n >= 1) {
		sequence.push_back(n);
		if (n % 3 == 0) {
			n /= 3;
		}
		else if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n - 1;
		}
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

vector<int> optimal_sequence(int n) {
	vector<int> sequence1;
	switch (n) {
	case 1:
		sequence1.push_back(1);
		return sequence1;
	case 2:
	case 3:
		sequence1.push_back(1);
		sequence1.push_back(n);
		return sequence1;
	}
	//sequence1 = optimal_sequence(n - 1);
	//unsigned int size1 = sequence1.size();
	if (n % 2 == 0 && n % 3 == 0) {
		vector<int> sequence2 = optimal_sequence(n / 2);
		vector<int> sequence3 = optimal_sequence(n / 3);
		unsigned int size2 = sequence2.size();
		unsigned int size3 = sequence3.size();
		if (size2 <= size3) {
			sequence2.push_back(n);
			return sequence2;
		}
		else {
			sequence3.push_back(n);
			return sequence3;
		}
		/*if (size1 <= size2) {
			if (size1 <= size3) {
				sequence1.push_back(n);
				return sequence1;
			}
			else {
				sequence3.push_back(n);
				return sequence3;
			}
		}
		else {
			if (size2 <= size3) {
				sequence2.push_back(n);
				return sequence2;
			}
			else {
				sequence3.push_back(n);
				return sequence3;
			}
		}*/
	}
	else if (n % 2 == 0) {
		sequence1 = optimal_sequence(n - 1);
		vector<int> sequence2 = optimal_sequence(n / 2);
		unsigned int size1 = sequence1.size();
		unsigned int size2 = sequence2.size();
		if (size1 <= size2) {
			sequence1.push_back(n);
			return sequence1;
		}
		else {
			sequence2.push_back(n);
			return sequence2;
		}
	}
	else if (n % 3 == 0) {
		sequence1 = optimal_sequence(n - 1);
		vector<int> sequence3 = optimal_sequence(n / 3);
		unsigned int size1 = sequence1.size();
		unsigned int size3 = sequence3.size();
		if (size1 <= size3) {
			sequence1.push_back(n);
			return sequence1;
		}
		else {
			sequence3.push_back(n);
			return sequence3;
		}
	}
	sequence1 = optimal_sequence(n - 1);
	sequence1.push_back(n);
	return sequence1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}
