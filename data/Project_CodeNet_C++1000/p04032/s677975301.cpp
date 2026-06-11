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
	
	REP(i,n-1){
		if(s[i]==s[i+1]){
			cout << i+1 << " " << i+2<<endl;
			return 0;
		}
		
		if(i<=n-2 && s[i]==s[i+2]){
			cout << i+1 << " " << i+3<<endl;
			return 0;
		}
	}
	
	cout << "-1 -1\n";
	
	
	return 0;
}