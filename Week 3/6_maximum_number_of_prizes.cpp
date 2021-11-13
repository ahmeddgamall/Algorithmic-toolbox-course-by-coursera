#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
	vector<int> summands;
	//write your code here
	int a = 1;
	while (n > 0) {
		summands.push_back(a);
		n -= a;
		++a;
		if (n < a) {
			summands.back() += n;
			break;
		}
	}
	return summands;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << ' ';
	}
}
