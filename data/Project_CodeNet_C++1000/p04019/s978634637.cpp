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
//__builtin_popcount(n)
using pi = pair<int,int>;
signed main(){
	string t; cin>>t;
	int m=t.size();
	bool n=0,s=0,e=0,w=0;
	rep(i,0,m){
		if(t[i]=='N')n=1;
		else if(t[i]=='S')s=1;
		else if(t[i]=='E')e=1;
		else w=1;
	}
	bool ok=true;
	if(s!=n)ok=false;
	if(w!=e)ok=false;
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}