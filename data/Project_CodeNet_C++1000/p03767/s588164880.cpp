#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	vector<int> a(n * 3);
	for(int i = 0; i < n * 3; i++)cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	a.resize(n * 2);
	ll sum = 0;

	for(int i = 1; i < n * 2; i += 2) {
		sum += a[i];
	}
	cout << sum << endl;
}