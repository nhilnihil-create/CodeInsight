#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
using ll = long long;
const int maxn = 300010;
ll n, x;
ll solve(ll a, ll b){
	if(b % a == 0)return b * 2;
	return b / a * a * 2 + a + b % a + solve(b % a, a - b % a);
}
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> x;
	cout << solve(n-x, x) + x << '\n';
}

