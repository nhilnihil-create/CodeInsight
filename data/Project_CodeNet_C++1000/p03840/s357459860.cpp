#include<map>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;

ll a[10];

int main() {
	REP(i, 1, 7) {
		cin >> a[i];
	}
	ll s = a[1] + a[2] + a[4] + a[5];
	ll ans1 = s - a[1] % 2 - a[4] % 2 - a[5] % 2;
	if (a[1] == 0 || a[4] == 0 || a[5] == 0) {
		cout << ans1 << endl;
		return 0;
	}
	ll ans2 = s - (a[1] - 1) % 2 - (a[4] - 1) % 2 - (a[5] - 1) % 2;
	cout << max(ans1, ans2) << endl;
	

}