#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
	//write your code here
	vector<vector<int>> value(w.size() + 1, vector<int>(W + 1));
	for (int i = 0; i <= w.size(); ++i) {
		value[i][0] = 0;
	}
	for (int i = 0; i <= W; ++i) {
		value[0][i] = 0;
	}
	for (int i = 1; i <= w.size(); ++i) {
		for (int j = 1; j <= W; ++j) {
			value[i][j] = value[i - 1][j];
			if (w[i - 1] <= j) {
				unsigned int val = value[i - 1][j - w[i - 1]] + w[i - 1];
				if (val > value[i][j]) {
					value[i][j] = val;
				}
			}
		}
	}
	return value[w.size()][W];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';
}
