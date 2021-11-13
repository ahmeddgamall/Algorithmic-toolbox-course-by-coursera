#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
	if (op == '*') {
		return a * b;
	}
	else if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else {
		assert(0);
	}
}

void MinAndMax(unsigned int i, unsigned int j, vector<vector<long long>> &M, vector<vector<long long>> &m, vector<int> &d, vector<char> &op) {
	long long maximum = std::numeric_limits<long long>::min();
	long long minimum = std::numeric_limits<long long>::max();
	for (unsigned int k = i; k < j; ++k) {
		long long a = eval(M[i][k], M[k + 1][j], op[k]);
		long long b = eval(M[i][k], m[k + 1][j], op[k]);
		long long c = eval(m[i][k], M[k + 1][j], op[k]);
		long long d = eval(m[i][k], m[k + 1][j], op[k]);
		minimum = min(min(min(a, b), min(c, d)), minimum);
		maximum = max(max(max(a, b), max(c, d)), maximum);
	}
	m[i][j] = minimum;
	M[i][j] = maximum;
}

long long get_maximum_value(const string &exp) {
	//write your code here
	unsigned int n = (exp.size() - 1) / 2;
	vector<int> d;
	vector<char> op;
	for (unsigned int i = 0; i < exp.size(); ++i) {
		if (i % 2 == 0) {
			d.push_back(exp[i] - '0');
		}
		else {
			op.push_back(exp[i]);
		}
	}
	vector<vector<long long>> M(d.size(), vector<long long>(d.size()));
	vector<vector<long long>> m(d.size(), vector<long long>(d.size()));
	for (unsigned int i = 0; i < d.size(); ++i) {
		M[i][i] = d[i];
		m[i][i] = d[i];
	}
	for (unsigned int s = 1; s < d.size(); ++s) {
		for (unsigned int i = 0; i < d.size() - s; ++i) {
			unsigned int j = i + s;
			MinAndMax(i, j, M, m, d, op);
		}
	}
	return M[0][d.size() - 1];
}

int main() {
	string s;
	std::cin >> s;
	std::cout << get_maximum_value(s) << '\n';
}
