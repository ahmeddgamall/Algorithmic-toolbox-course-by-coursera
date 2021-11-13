#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t right, size_t ave) {
	long long number_of_inversions = 0;
	size_t mid = ave;
	size_t index = left;
	size_t l = left;
	while (left < mid && ave < right) {
		if (a[left] > a[ave]) {
			b[index] = a[ave];
			number_of_inversions += mid-left;
			++ave;
		}
		else {
			b[index] = a[left];
			++left;
		}
		++index;
	}
	if (ave == right) {
		while (left < mid) {
			b[index] = a[left];
			++left;
			++index;
		}
	}
	else if (left == mid) {
		while (ave < right) {
			b[index] = a[ave];
			++ave;
			++index;
		}
	}
	for (size_t i = l; i < right; ++i) {
		a[i] = b[i];
	}
	return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	long long number_of_inversions = 0;
	if (right <= left + 1) return number_of_inversions;
	size_t ave = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave, right);
	//write your code here
	number_of_inversions += merge(a, b, left, right, ave);
	return number_of_inversions;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	vector<int> b(a.size());
	std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
