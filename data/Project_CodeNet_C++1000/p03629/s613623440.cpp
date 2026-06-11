#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;
ll mpow(ll a, ll b){ll r=1;a%=mod;while(b){r=r*((b%2)?a:1)%mod,a=a*a%mod,b>>=1;}return r;}


int main() {
	string s,t; cin>>s;
	int n=s.size();
	vector<int> a(n+1,0),b(n+1,0);
	rrep(i,n-1,-1){
		a[i]=a[i+1]|(1<<(s[i]-'a'));
		b[i]=b[i+1];
		while(a[i]&(1<<b[i]))b[i]++;
		if(b[i]>=26) a[i]=0,b[i]=0;
	}
	rep(i,0,n){
		t+=(char)(b[i]+'a');
		while((i<n)&&(s[i]!=*t.rbegin()))i++;
	}
	cout<<t<<endl;
	return 0;
}