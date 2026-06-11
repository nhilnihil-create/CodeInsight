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
	int n,m,r;
	cin >> n >> m >> r;
	const int INF = 1e9;
	vector<vector<int>> d(n,vector<int>(n,INF));
	REP(i,n) d[i][i] = 0;
	vector<int> destination(r);
	REP(i,r){
		cin >> destination[i];
		destination[i]--;
	}
	REP(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		d[a-1][b-1] = c;
		d[b-1][a-1] = c;
	}
	REP(k,n){
 		REP(i,n){
 			REP(j,n){
 				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
 			}
 		}
 	}
	
	sort(destination.begin(),destination.end());
	int ans = 1e9;
	do{
		int tmp=0;
		REP(i,r-1){
			tmp += d[destination[i]][destination[i+1]];
		}
		chmin(ans,tmp);
	}while(next_permutation(destination.begin(),destination.end()));
	
	cout << ans << endl;
	
		
	return 0;
}