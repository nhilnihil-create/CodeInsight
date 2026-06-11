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
	int n,a,b; cin>>n>>a>>b;
	string s; cin>>s;
	int m=s.size();
	int cnt=0,f=0;
	rep(i,0,m){
		char c=s[i];
		if(c=='c'){
			cout<<"No"<<endl;
			continue;
		}
		else if(c=='a'){
			if(cnt<a+b){
				cout<<"Yes"<<endl;
				++cnt;
			}
			else cout<<"No"<<endl;
		}
		else {
			if(cnt<a+b && f<b){
				cout<<"Yes"<<endl;
				++cnt; ++f;
			}
			else cout<<"No"<<endl;
		}
	}

	return 0;
}