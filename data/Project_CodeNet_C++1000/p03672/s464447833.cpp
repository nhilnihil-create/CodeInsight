#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	string s; cin>>s;
	int m=s.size();
	rep(i,0,2) s.pop_back();
	rep(i,0,m/2){
		int n=s.size();
		bool ok=true;
		rep(j,0,n/2){
			if(s[j]!=s[(n/2)+j]) ok=false;
		}
		if(ok){
			cout<<s.size();
			return 0;
		}
		rep(k,0,2) s.pop_back();
	}
	
	return 0;
}