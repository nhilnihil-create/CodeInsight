#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	return (b ? gcd(b, a % b) : a);
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

long long Solve(vector<long long> a) {
	int n = (int) a.size();
	long long ret = a[0];
	for(int i = 1; i < n; i++) {
		ret = lcm(ret, a[i]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << Solve(a) << endl;
}