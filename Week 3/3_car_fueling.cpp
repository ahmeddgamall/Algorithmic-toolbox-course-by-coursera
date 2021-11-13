#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
//using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	// write your code here
	int refills = 0;
	int current_refill = 0;
	int last_refill = 0;
	while (last_refill < dist) {
		last_refill = current_refill;
		for (static int i = 0; i < stops.size(); ++i) {
			if (stops[i] - last_refill <= tank) {
				current_refill = stops[i];
			}
			else {
				break;
			}
		}
		if (current_refill == last_refill) {
			return -1;
		}
		else if (current_refill == stops[stops.size() - 1]) {
			if (dist - last_refill <= tank) {
				return refills;
			}
			else if (dist - stops[stops.size() - 1] <= tank) {
				return refills + 1;
			}
			else {
				return -1;
			}
		}
		else {
			refills++;
		}
	}
	return refills;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
