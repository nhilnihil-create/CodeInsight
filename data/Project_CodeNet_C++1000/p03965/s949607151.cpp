//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1LL<<60LL)
typedef long long ll;

using namespace std;

int main() {
	string s; cin >> s;
	ll ans = s.size() / 2;
	for (auto a : s) {
		if (a == 'p') ans -= 1;
	}
	cout << ans << endl;
}