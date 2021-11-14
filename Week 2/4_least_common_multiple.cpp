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

long long lcm(int a, int b) {
	return ((long long)a * b) / gcd(a, b);
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << lcm(a, b) << std::endl;
	return 0;
}
