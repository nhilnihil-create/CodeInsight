#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define MOD 1000000007


typedef long long ll;
typedef pair<ll,ll> P;

int dp[222222];
int ok[26];
string str;
vector<vector<int> > v(26);

int dfs(int n){
	DBG(
	cout << "DFS " << n << endl;
	);
	if(dp[n] != INF)return dp[n];
	int ans = INF;
	REP(i,26){
		auto it = lower_bound(ALL(v[i]),n);
		DBG(cout << "IN DFS " << n << " IT IS " << *it << endl;);
		ans = min(ans,dfs((*it)+1) + 1);
	}
	return dp[n] = ans;
}

void dfs2(int n){
	if(dp[n] == 1){
		REP(i,26)ok[i] = 0;
		for(int i = n;i < str.size();i++){
			ok[str[i]-'a']++;
		}
		REP(i,26){
			if(ok[i] == 0){
				char tmp = 'a' + i;
				cout << tmp << endl;
				return;
			}
		}
	}
	
	REP(i,26){
		auto it = lower_bound(ALL(v[i]),n);
		if(dp[*it+1] + 1 == dp[n]){
			char tmp = 'a' + i;
			cout << tmp;
			dfs2(*it+1);
			return;
		}		
	}
	return;
}

int main()
{
	int tmp = 0;
	cin >> str;
	REP(i,222222)dp[i] = INF;
	dp[str.size()] = 1;
	
	REP(i,str.size()){
		v[str[i]-'a'].PB(i);
	}
	
	REP(i,str.size()){
		ok[str[str.size()-1-i]-'a']++;
		if(ok[str[str.size()-1-i]-'a'] == 1){
			tmp++;
			if(tmp == 26)break;
		}
		dp[str.size() - 1 - i] = 1;
	}
	DBG(SHOW1d(dp,str.size()););	
	dfs(0);
	DBG(SHOW1d(dp,str.size()););
	dfs2(0);
	
	return 0;
}