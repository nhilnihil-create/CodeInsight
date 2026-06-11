#include <bits/stdc++.h>
using namespace std;

const long long MOD = (1e9)+7;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long res = 1, curr = 0;
	cin >> n;
	for(int i = 0, x; i < n; i++, curr++) {
		cin >> x;
		if(x <= 2*curr) res = (res*(curr+1))%MOD, curr--;
	}
	while(curr) res = (res*curr--)%MOD;
	cout << res;
}