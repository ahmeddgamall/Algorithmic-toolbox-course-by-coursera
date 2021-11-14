#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge(long long n, long long m) {
	vector<long long> fibonacci;
	fibonacci.push_back(0);
	fibonacci.push_back(1);
	long long current = 1;
	long long previous = 0;
	while (1) {
		fibonacci.push_back((fibonacci[current] + fibonacci[previous]) % m);
		current++;
		previous++;
		if (fibonacci[current] == 1 && fibonacci[previous] == 0) {
			break;
		}
	}
	unsigned int period = fibonacci.size() - 2;
	return fibonacci[n % period];
}

int main() {
	long long n, m;
	cin >> n >> m;
	cout << get_fibonacci_huge(n, m) << '\n';
}
