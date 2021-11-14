#include <iostream>

int get_fibonacci_last_digit(int n) {
	if (n <= 1)
		return n;

	int F_2 = 0;
	int F_1 = 1;
	int F;
	for (int i = 2; i <= n; ++i) {
		F = (F_2 + F_1) % 10;
		F_2 = F_1;
		F_1 = F;
	}

	return F;
}

int main() {
	int n;
	std::cin >> n;
	int c = get_fibonacci_last_digit(n);
	std::cout << c << '\n';
}
