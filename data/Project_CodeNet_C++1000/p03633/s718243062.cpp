#include<bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
	if(y == 0) return x;
	else return gcd(y, x % y);
}

int main() {
	int n; cin >> n;
	long long t[n];
	for(int i = 0; i < n; i++) cin >> t[i];
	long long g = t[0];
	for (int i = 1; i < n; i++)
	{
		g = g / gcd(g, t[i]) * t[i];
	}
	cout << g << endl;
	return 0;
}
