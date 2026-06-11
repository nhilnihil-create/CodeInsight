#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	string s,t,u;
	cin>>s>>t>>u;
	queue<char> aq,bq,cq;
	rep(i,0,s.size()) aq.push(s[i]);
	rep(i,0,t.size()) bq.push(t[i]);
	rep(i,0,u.size()) cq.push(u[i]);
	char ans='g';
	char v='a';
	while(true){
		if(v=='a'){
			if(aq.empty()){
				ans='A';
				break;
			}
			v=aq.front();
			aq.pop();
		}
		if(v=='b'){
			if(bq.empty()){
				ans='B';
				break;
			}
			v=bq.front();
			bq.pop();
		}
		if(v=='c'){
			if(cq.empty()){
				ans='C';
				break;
			}
			v=cq.front();
			cq.pop();
		}
	}
	cout<<ans;
		
	return 0;
}