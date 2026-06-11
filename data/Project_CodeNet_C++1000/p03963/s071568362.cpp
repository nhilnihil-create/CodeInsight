#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	cout << k * (ll)pow(k - 1, n - 1);
}