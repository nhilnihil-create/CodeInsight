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
	int n; cin>>n;
	vl vec(n);
	vl s(0);
	vl t(0);
	bool v=true;
	rep(i,0,n){
		ll a; cin>>a;
		if(v) s.push_back(a);
		else t.push_back(a);
		if(v) v=false;
		else v=true;
	}
	if(n%2==0){
		reverse(all(t));
		rep(i,0,t.size()){
			cout<<t[i]<<" ";
			//cout<<"t ";
		}
		rep(i,0,s.size()){
			cout<<s[i]<<" ";
			//cout<<"s ";
		}
	}
	else{
		reverse(all(s));
		rep(i,0,s.size()){
			cout<<s[i]<<" ";
			//cout<<"s ";
		}
		rep(i,0,t.size()){
			cout<<t[i]<<" ";
			//cout<<"t ";
		}
	}
	return 0;
}