#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a,b; cin>>a>>b;
	vector<int> pa,pb;
	pa.emplace_back(0);
	for(auto &i:a){
		if(i=='A') pa.emplace_back(pa.back()+1);
		else       pa.emplace_back(pa.back()+2);
	}
	pb.emplace_back(0);
	for(auto &i:b){
		if(i=='A') pb.emplace_back(pb.back()+1);
		else       pb.emplace_back(pb.back()+2);
	}
	int q; cin>>q;
	int s1,t1,s2,t2;
	while(q--){
		cin>>s1>>t1>>s2>>t2;
		int a1=pa[t1]-pa[s1-1];
		int a2=pb[t2]-pb[s2-1];
		if(a1%3==a2%3) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}



























