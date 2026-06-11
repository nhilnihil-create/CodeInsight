#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll a, ll b){
	if(a == b) return a;
	if(b > a) return solve(b, a);
	ll k = ((a-1) / b);
	return solve(a - k * b, b) + 2 * k * b;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, x;
	cin >> n >> x;
	ll ans = solve(x, n-x) + n;
	cout << ans << '\n';
}