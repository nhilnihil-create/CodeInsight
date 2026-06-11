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
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n;
	cin >> n;
	
	vector<ll> a;
	for(ll i=1; i*i<=n; i++){
		if(n%i==0){
			a.push_back(i);
			a.push_back(n/i);
		}
	}
	
	int sz = (int)a.size();
	cout << max((int)log10(a[sz-1]), (int)log10(a[sz-2]))+1 << endl;
	
	return 0;
}