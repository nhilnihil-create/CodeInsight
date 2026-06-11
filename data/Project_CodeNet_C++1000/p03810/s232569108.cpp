#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
long long arr[MAXN], all;
vector<int> vec;

long long gcd(long long v, long long u) {
	return v ? gcd(u % v, v) : u;
}

bool solve() {
	all = 0;
	vec.clear();
	for (int i = 0; i < n; i++) {
		all += arr[i];
		if (arr[i] & 1)
			vec.push_back(i);
	}
	if ((all & 1) != (n & 1))
		return true;
	if (vec.size() != 1 || arr[vec[0]] == 1)
		return false;
	arr[vec[0]]--;
	int GCD = arr[0];
	for (int i = 1; i < n; i++)
		GCD = gcd(GCD, arr[i]);
	for (int i = 0; i < n; i++) 
		arr[i] /= GCD;
	return !solve();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		all += arr[i];
	}
	if (n <= 2) {
		if ((all & 1) == (n & 1))
			cout << "Second\n";
		else
			cout << "First\n";
		return 0;
	}
	if (solve()) 
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}