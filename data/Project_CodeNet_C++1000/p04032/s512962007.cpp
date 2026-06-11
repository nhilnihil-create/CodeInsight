#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	string s;
	cin >> s;
	int n = s.size();
	
	vector<vector<int>> sum(n+1, vector<int>(26,0));
	REP(i,n){
		REP(j,26) sum[i+1][j] = sum[i][j];
		sum[i+1][s[i]-'a']++;
	}
	
	REP(i,n-1) REP(j,26){
		// [i, now)
		int now;
		now = n;
		while(now - i > 1){
			if(sum[now][j]-sum[i][j] > (now-i)/2){
				cout << i+1 << " " << now << endl;
				return 0;
			}else{
				now = i-1 + (sum[now][j]-sum[i][j])*2;
			}
		}
	}
	
	cout << "-1 -1\n";
	
	
	return 0;
}