#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
ll mod=1e9+7;
ll fac(ll n){
	ll i=1;
	ll ans=1;
	while(i <= n){
		ans*=i;
		ans%=mod;
		i++;
	}
	return ans;
}


int main(){
	ll d,m;
	cin >> d >> m;
	//cout << fac(100000)<<"\n";
	if(m==d+1) cout << ((fac(m))*(fac(d)))%mod;
	else if(d==m+1) cout << ((fac(m))*(fac(d)))%mod;
	else if (d==m) cout << (2*((fac(m))*(fac(d))%mod))%mod;
	else cout << 0;
	return 0;
}