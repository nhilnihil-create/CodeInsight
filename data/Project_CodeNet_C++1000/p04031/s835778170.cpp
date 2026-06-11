#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int is[n];
	int avg1 = 0;
	int avg2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> is[i];
		avg1 += is[i];
		avg2 += is[i];
	}
	int temp = !(!(avg1 % n));
	avg1 /= n;
	avg1 += temp;
	avg2 /= n;
	int cost1 = 0;
	int cost2 = 0;
	for (int i: is) {
		cost1 += (i-avg1) * (i-avg1);
		cost2 += (i-avg2) * (i-avg2);
	}
	cout << min(cost1, cost2) << endl;
	return 0;
}