#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
using pl = pair<ll,ll>;
signed main(){
	ll n,L; cin >> n >> L;
	ll sum=0;
	vl a(n); rep(i,0,n)cin >> a[i];
	rep(i,1,n){
		if(a[i]+a[i-1]>=L){
			cout<<"Possible"<<endl;
			rep(j,0,i-1)cout<<j+1<<endl;
			for(ll j = n-1; j>= i; --j)cout<<j<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;



	return 0;
}