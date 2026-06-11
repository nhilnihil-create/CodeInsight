#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

void solve() {
	ll x;
	cin >> x;
	ll t  = x / 11;
	t = 2 * t;
	int r = x % 11;
	if(r == 0) ;
	else if(r <= 6) t++;
	else if(r <= 11) t += 2;
	cout << t << endl;
}
	

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
