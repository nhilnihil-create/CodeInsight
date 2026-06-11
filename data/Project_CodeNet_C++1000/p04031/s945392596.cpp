#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i: a) cin >> i;
	int ans = INT_MAX;
	for(int diff = -100; diff <= 100; diff++) {
		int cur = 0;
		for(int i = 0; i < n; i++) {
			cur += (a[i] - diff)*(a[i] - diff);
		}
		ans = min(ans, cur);
	}
	cout << ans;
}
