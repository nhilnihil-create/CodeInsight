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
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	vector<char> a(26),b(26);
	rep(i,0,26){
		a[i]='a'+i;
		b[i]='A'+i;
	}
	string ans="";
	vector<string> s(3);
	rep(i,0,3) cin>>s[i];
	rep(i,0,3){
		rep(j,0,26){
			if(a[j]==s[i][0]){
				ans.push_back(b[j]);
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}