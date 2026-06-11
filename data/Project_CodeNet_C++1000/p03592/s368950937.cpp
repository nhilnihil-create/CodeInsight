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
	int n,m,k;
	cin >> n >> m >> k;
	
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=m; ++j){
			int c = (n-i)*j + (m-j)*i;
			if(c==k){
				cout << "Yes" << endl;
				return 0;
			}	
		}
	}
	
	cout << "No" << endl;
	
	return 0;
}