#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<unsigned int> a) {
	sort(a.begin(), a.end());
	unsigned long long half = a.size() / 2;
	for (unsigned int i = 0; i < half; ++i) {
		if (a[i] == a[i + half]) {
			return 1;
		}
	}
	if (a.size()%2 == 1 && a[half] == a[half+half]) {
		return 1;
	}
	else {
		return 0;
	}
}

int m(vector<unsigned int> a) {
	unsigned int count = 0;
	for (unsigned int i = 0; i < a.size(); ++i) {
		count = 0;
		for (unsigned int j = 0; j < a.size(); ++j) {
			if (a[i] == a[j]) {
				count++;
				if (count > a.size() / 2) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	unsigned int n;
	std::cin >> n;
	vector<unsigned int> a(n);
	for (unsigned int i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << get_majority_element(a) << '\n';
}
