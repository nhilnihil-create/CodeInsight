#include<bits/stdc++.h>
using namespace std;

int where(int x, vector<int>& v) {
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
	int n;
	cin >> n;

	vector<int> num(n);
	for(int &i : num) cin >> i;

	vector<int> v = num;
	sort(v.begin(), v.end());

	int ans = 0;
	for(int i=0; i<n; i++) {
		int d = abs(i - where(num[i], v));
		if(d % 2) ans++;
	}

	cout << ans / 2;
}