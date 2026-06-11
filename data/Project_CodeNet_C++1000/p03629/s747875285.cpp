#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)

typedef long long ll;
typedef pair<double,ll> P;

int dp[222222];
bool ok[222222];
int mp[222222][26];
int nxt[26];

int main(){
	
	string str;
	cin >> str;
	str = "X" + str + "X";
	
	REP(i,26)nxt[i] = str.size() - 1;
	for(int i = str.size() - 1;i >= 0;i--){
		REP(j,26)mp[i][j] = nxt[j];
		if(str[i] != 'X')nxt[str[i] - 'a'] = i;
	}
	
	REP(i,222222)dp[i] = INF;
	dp[0] = 0;
	REP(i,str.size()){
		REP(j,26){
			dp[mp[i][j]] = min(dp[mp[i][j]], dp[i] + 1);
		}
	}
	
	ok[str.size() - 1] = true;
	for(int i = str.size() - 1;i >= 0;i--){
		REP(j,26){
			if(dp[mp[i][j]] == dp[i] + 1 && ok[mp[i][j]])ok[i] = true;
		}
	}
	
	int now = 0;
	while(now != str.size() - 1){
		REP(j,26){
			if(dp[mp[now][j]] == dp[now] + 1 && ok[mp[now][j]]){
				char c = 'a' + j;
				cout << c;
				now = mp[now][j];
				break;
			}
		}
	}
	
	cout << endl;
			
	
	return 0;
}
