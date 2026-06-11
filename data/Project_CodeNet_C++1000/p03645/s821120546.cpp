#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
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
string dfs(mti vec,int x,int cnt,int n)
{
	if(cnt==0){
		if(x==n) return "POSSIBLE";
		else return "IMPOSSIBLE";
	}
	for(int c:vec[x]){
		string s;
		s=dfs(vec,c,cnt-1,n);
		if(s=="POSSIBLE") return s;
	}
	return "IMPOSSIBLE";
}

signed main(){
	int n,m; cin>>n>>m;
	mti vec(n+1,vi(0));
	vi one(0);
	rep(i,0,m){
		int a,b; cin>>a>>b;
		if(a==1) one.push_back(b);
		if(b==1) one.push_back(a);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	string ans="IMPOSSIBLE";
	if(one.size()==0) ans=dfs(vec,1,2,n);
	else{
		for(int c:one){
			for(int d:vec[c]){
				if(d==n){
					cout<<"POSSIBLE";
					return 0;
				}
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}