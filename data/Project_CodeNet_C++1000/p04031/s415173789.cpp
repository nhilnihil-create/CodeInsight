#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	int avg = 0;
	for (int i = 0; i < v.size(); i++) {
		cin >> v.at(i);
		avg += v.at(i);
	}

	int avg1, avg2;
	avg1 = ceil((double)avg / N);
	avg2 = floor((double)avg / N);
	//cout << "avg1:" << avg1 << endl;
	//cout << "avg2:" << avg2 << endl;

	int cost1 = 0,
		cost2 = 0;
	for (int i = 0; i < v.size(); i++) {
		int x1, x2;
		x1 = avg1 - v.at(i);
		x2 = avg2 - v.at(i);

		x1 *= x1;
		x2 *= x2;

		cost1 += x1;
		cost2 += x2;
	}

	int a;
	if (cost1 > cost2) {
		a = cost2;
	}
	else {
		a = cost1;
	}
	cout << a << endl;
}