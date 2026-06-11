#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	ll push = 0;
	for(int i = 0; i < n; ++i){
		ll p = 0;
		if((a[i] +push) % b[i] != 0){
			p = b[i] - (a[i] + push) % b[i];
		}
		push += p;
	}
	cout << push << endl;
	return 0;
}

