#include <iostream>
#include <vector>

using std::vector;

int min(int x, int y, int z) {
	if (x <= y) {
		if (x <= z) {
			return x;
		}
		else {
			return z;
		}
	}
	else {
		if (y <= z) {
			return y;
		}
		else {
			return z;
		}
	}
}

int get_change(int m) {
	//write your code here
	vector<int> change(m + 1);
	if (m > 4) {
		change[0] = 0;
		change[1] = 1;
		change[2] = 2;
		change[3] = 1;
		change[4] = 1;
	}
	else{
		switch (m) {
		case 1:
		case 3:
		case 4:
			return 1;
		case 2:
			return 2;
		}
	}
	for (int i = 5; i <= m; ++i) {
		change[i] = min(change[i - 1], change[i - 3], change[i - 4]) + 1;
	}
	return change[m];
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
