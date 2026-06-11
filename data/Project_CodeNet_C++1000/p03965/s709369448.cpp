#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int dp[100001];

int main(){
	int n;
	string s;
	cin >> s;
	n = (int)s.size();
	
	int p=0,g=0;
	int win=0;
	REP(i,n){
		if(s[i]=='g'){
			if(p < g){
				p++;
				win++;
			}else{
				g++;
			}
		}else{
			if(p < g){
				p++;
			}else{
				g++;
				win--;
			}
		}
	}
	
	cout << win << endl;
	
	return 0;
}