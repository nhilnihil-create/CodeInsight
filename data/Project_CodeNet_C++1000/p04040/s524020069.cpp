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
int cbn(int n, int r) {
	int rt = 1;
	for (int i = 1; i <= n; i++) { rt *= i; rt %= mod; }
	for (int i = 1; i <= r; i++) { rt *= f1(i, mod - 2); rt %= mod; }
	for (int i = 1; i <= n - r; i++) { rt *= f1(i, mod - 2); rt %= mod; }
	return rt;
}
int h, w, a, b;
int ans = 0, kl = 1, kr = 1;
signed main() {
	cin >> h >> w >> a >> b; kr = cbn(h + w - b - 2, h - 1);
	for1(i, h - a) {
		//(b-1)+(i-1)C(i-1)*(h-1)+(w-b-1)C(h-1)
		//kl = cbn(b + i - 2, i - 1), kr = cbn(h + w - b - 1 - i, h - i);
		ans += kl * kr % mod; ans %= mod;
		kl *= b + i - 1; kl %= mod; kl *= f1(i, mod - 2); kl %= mod;
		kr *= h - i; kr %= mod; kr *= f1(h + w - b - 1 - i, mod - 2); kr %= mod;
	}
	cout << ans << endl;
}