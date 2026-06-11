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
	int n;
	cin >> n;
	map<int,int> a;
	REP(i,n){
		int in;
		cin >> in;
		a[in]++;
	}
	
	vector<int> four,two;
	for(auto x:a){
		if(x.second >= 2) two.push_back(x.first);
		if(x.second >= 4) four.push_back(x.first);
	}
	
	ll ans = 0;
	if((int)four.size()!=0){
		sort(four.begin(),four.end(),greater<int>());
		ans = (ll)four[0]*(ll)four[0];
	}
	
	
	if((int)two.size()>=2){
		sort(two.begin(),two.end(),greater<int>());
		chmax(ans, (ll)two[0]*(ll)two[1]);
	}
	
	cout << ans << endl;
	
	return 0;
}