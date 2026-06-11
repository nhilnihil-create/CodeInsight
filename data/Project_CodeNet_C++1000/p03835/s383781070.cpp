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
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int k,s;
	cin >> k >> s;
	
	ll ans=0;
	for(int x=0; x<=k; ++x){
		for(int y=0; y<=k; ++y){
			if(s-(x+y)>=0 && s-(x+y)<=k) ans++; 
		}
	}
	
	cout << ans << endl;
	
	return 0;
}