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
	int n,k;
	cin >> n >> k;
	int d[10] = {};
	REP(i,k) {
		int in;
		cin >> in;
		d[in] = 1;
	}
	
	int num = n;
	while(true){
		bool ok = true; 
		string s = to_string(num);
		REP(i,s.size()){
			if(d[s[i]-'0']) ok = false;
		}
		if(ok) break;
		else num++;
	}
	
	cout << num << endl;

	return 0;
}