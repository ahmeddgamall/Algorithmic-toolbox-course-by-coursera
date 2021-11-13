#include <iostream>
#include <string>

using std::string;

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

int edit_distance(const string &str1, const string &str2) {
	//write your code here
	int** distance = new int*[str1.size() + 1];
	for (int i = 0; i <= str1.size(); ++i) {
		distance[i] = new int[str2.size() + 1];
		distance[i][0] = i;
	}
	for (int i = 0; i <= str2.size(); ++i) {
		distance[0][i] = i;
	}
	for (int i = 1; i <= str1.size(); ++i) {
		for (int j = 1; j <= str2.size(); ++j) {
			if (str1[i - 1] == str2[j - 1]) {
				distance[i][j] = min(distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1]);
			}
			else {
				distance[i][j] = min(distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1] + 1);
			}
		}
	}
	return distance[str1.size()][str2.size()];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
