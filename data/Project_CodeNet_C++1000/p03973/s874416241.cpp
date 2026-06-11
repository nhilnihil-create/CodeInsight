#include <bits/stdc++.h>
using namespace std;
#define B begin()
#define E end()
#define F first
#define S second
#define pub push_back
#define mkp make_pair
#define migmig ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long double ld;
typedef long long ll; 
typedef vector<ll> vll;
typedef map<ll,ll> mll;
const ll N=1e5+5;
ll n, k, sum, l, x, m, i, a[N], ans;
int main(){
	cin>> n;
	for(ll i=0; i<n; i++){
		cin>> a[i];
	}
	x = 2;
	ans = a[0] - 1;
	for(ll i=1; i<n; i++){
		ans += (a[i]) / x;
		if(a[i] % x == 0) ans--;
		if(a[i]==x)x++;
	}
	cout<<ans;
}








