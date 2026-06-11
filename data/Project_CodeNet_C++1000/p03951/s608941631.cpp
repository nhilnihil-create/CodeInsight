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
#define mod 200003
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
using pl = pair<ll,ll>;
using vvb=vector<vector<bool>>;
using vb= vector<bool>;
ll f(ll a,ll b,ll p){
	if(b==0) return 1;
	if(b%2==0){
		ll t=f(a,b/2,p);
		return t*t%p;
	}
	return a*(f(a,b-1,p))%p;
} 

//__builtin_popcount()
signed main(){
	int n; cin>>n;
	string s,t; cin>>s>>t;
	ll ans=0;
	rep(i,0,n){
		rep(j,0,n){
			if(s[i]==t[j]){
				ll cnt=0;
				ll a=i,b=j;
				while(a<n && b<n){
					if(s[a]!=t[b])break;
					a++; b++;
					cnt++;
				}
				chmax(ans,cnt);
			}
		}
	}
	cout<<2*n-ans<<endl;

	


	return 0;
}