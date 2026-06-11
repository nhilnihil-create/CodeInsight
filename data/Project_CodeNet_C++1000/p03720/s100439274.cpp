#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> road(2), cnt(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 2; j++)
		{
		cin >> road.at(j);
		cnt.at((road.at(j))-1)++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << cnt.at(i) << endl;
	}

}
