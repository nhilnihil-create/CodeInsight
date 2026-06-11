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
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	string s1,s2;
	cin >> s1 >> s2;
	
	const ll mod = 1000000007;
	ll ans = 1;
	for(int i=0; i<n; i++){
		if(s1[i]==s2[i]){
			if(i==0){
				ans = 3;
			}else if(s1[i-1]==s2[i-1]){
				ans = (ans*2)%mod;
			}
		}else{
			if(i==0){
				ans = 6;
			}else if(s1[i-1]==s2[i-1]){
				ans = (ans*2)%mod;
			}else{
				ans = (ans*3)%mod;
			}
			i++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}