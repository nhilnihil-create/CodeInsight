#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

//繰り返し二乗法
ll mod_pow(ll x,ll n){
	ll res = 1;
	while(n > 0){
		if(n & 1){
			res = res * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main(){
	int n;cin>>n;
	vector<ll> t(n);
	vector<ll> a(n);
	vector<ll> high(n,LINF);
	for(int i = 0; i < n; i++) {
		cin>>t[i];
	}
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	high[0] = t[0];
	for(int i = 1; i < n; i++) {
		if(t[i] > t[i - 1]){
			high[i] = t[i];
		}
	}
	if (high[n - 1] != LINF && high[n - 1] != a[n - 1]){
		cout << 0 << endl;
		return 0;
	}
	high[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		if(high[i] != LINF && a[i] < high[i]){
			cout << 0 << endl;
			return 0;
		}
		if(a[i] > a[i + 1]){
			if(high[i] != LINF && high[i] != a[i]){
				cout << 0 << endl;
				return 0;
			}
			high[i] = a[i];
		}
	}
	ll l,r;
	ll dist;
	ll ans = 1;
	for(int i = 0; i < n - 1; i++) {
		// cout << high[i] << endl;
		if (high[i + 1] == LINF){
			if(high[i] != LINF){
				l = high[i];
				dist= 1;
			}
			else{
				dist++;
			}			
		}
		if(high[i + 1] != LINF && high[i] == LINF){
			// cout << "l " << l << " r " << r << " dist " << dist << " pow " << mod_pow(min(l,r),dist) << endl;
			r = high[i + 1];
			ans *= mod_pow(min(l,r),dist);
			ans %= mod;
		}
	}
	cout << ans << endl;

	return 0;
}