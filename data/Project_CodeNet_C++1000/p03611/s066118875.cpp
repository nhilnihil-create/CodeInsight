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

int v[100002];

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i,n) cin >> a[i];
	
	REP(i,n){
		v[a[i]]++;
		v[a[i]+1]++;
		v[a[i]+2]++;
	}
	
	int ans=0;
	REP(i,100002){
		chmax(ans, v[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}