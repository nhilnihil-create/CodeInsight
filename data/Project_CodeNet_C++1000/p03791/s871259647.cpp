#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
#define all(x) x.begin(),x.end()
#define puts(x) cout << x << endl
using namespace std;
int input() {
	int r;
	cin >> r;
	//scanf("%lld", &r);
	return r;
}
int f1(int a, int p) {
	if (p == 1)return a;
	if (p % 2)return f1(a, p - 1) * a % mod;
	else return f1(a * a % mod, p / 2) % mod;
}
int n, a[123456], ans = 1, k;
signed main() {
	cin >> n;
	for1(i, n) {
		cin >> a[i];
		if ((a[i] + 1) / 2 < i - k)
			ans = ans * (i - k++) % mod;
	}
	for1(i, n - k) { ans *= i; ans %= mod; }
	puts(ans);
}