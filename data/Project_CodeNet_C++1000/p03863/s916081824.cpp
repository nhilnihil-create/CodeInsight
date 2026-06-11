#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int INF = 2e9;



int main() {
	string s; cin >> s;
	if ((s[0] == s[s.size() - 1]) ^ (s.size() % 2)) printf("First");
	else printf("Second");
	return 0;
}
