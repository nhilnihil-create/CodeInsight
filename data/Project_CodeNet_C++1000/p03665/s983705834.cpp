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
int n, p, cnt[3], k = 0, c = 1;
signed main() {
	cin >> n >> p;
	while (n--)cnt[input() % 2]++;
	for (int i = p; i <= cnt[1]; i += 2) {
		if (i == 1)c = cnt[1];
		k += c;
		c *= (cnt[1] - i) * (cnt[1] - i - 1);
		c /= (i + 1) * (i + 2);
	}
	for0(i, cnt[0])k *= 2;
	puts(k);
}