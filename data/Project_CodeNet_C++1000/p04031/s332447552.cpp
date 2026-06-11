#include <bits/stdc++.h>
#define MAX 4000000
using namespace std;

int main() {
	int n;
	int mincost = MAX;
	cin >> n;
	vector<int> input;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	sort(input.begin(), input.end());
	for (int i = input.at(0); i <= input.at(n - 1); i++) {
		int cost = 0;
		for (int j = 0; j < n; j++) {
			cost += (input.at(j) - i) * (input.at(j) - i);
		}
		if (cost < mincost) mincost = cost;
	}

	cout << mincost << endl;

}