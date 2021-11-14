#include <iostream>

int gcd(int a, int b) {
	if (b > a) {
		std::swap(a, b);
	}
	while (b > 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << gcd(a, b) << std::endl;
	return 0;
}
