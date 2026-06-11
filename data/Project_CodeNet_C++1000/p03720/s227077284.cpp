#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> city(n ,0);
	for (int i = 0; i < m*2; i++)
	{
		int j;
		cin >> j;
		city.at(j - 1)++;
	}

	for (int i = 0; i < n; i++)
	{
		cout << city.at(i) << endl;
	}

}
