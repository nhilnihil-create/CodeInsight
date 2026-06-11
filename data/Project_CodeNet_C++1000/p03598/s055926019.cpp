#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, k;
	int sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		int a = k - x;
		if (x > a)
		{
			sum += 2 * a;
		}
		else{
			sum += 2 * x;
		}
	}
	cout << sum << endl;
}