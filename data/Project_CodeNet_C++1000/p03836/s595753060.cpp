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
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int sx,sy,tx,ty; cin>>sx>>sy>>tx>>ty;
	string ans;
	rep(i,0,ty-sy) ans.push_back('U');

	rep(i,0,tx-sx) ans.push_back('R');
			
	rep(i,0,ty-sy) ans.push_back('D');
	
	rep(i,0,tx-sx+1) ans.push_back('L');
	
	rep(i,0,ty-sy+1) ans.push_back('U');
	
	rep(i,0,tx-sx+1) ans.push_back('R');
	
	ans.push_back('D');
	ans.push_back('R');
	
	rep(i,0,ty-sy+1) ans.push_back('D');
	
	rep(i,0,tx-sx+1) ans.push_back('L');
	
	ans.push_back('U');
	cout<<ans;
	return 0;
}