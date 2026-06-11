#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int imp(){
	cout << "Impossible" << endl;
	return 0;
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for( auto &k : a ) cin >> k;
	int d = *max_element(a.begin(), a.end());
	vector<int> g(n+1);
	fill_n(g.begin(), n+1, 0);
	for( auto k : a ) ++g[k];
	for( int k = d; k >= 1; --k ){
		if( k > (d+1)/2 && g[k] < 2 ){
			// cout << "case 0: g[k] = " << g[k] << endl;
			return imp();
		}
		if( k == (d+1)/2 ){
			if( d % 2 == 0 && g[k] != 1 ){
				// cout << "case 1: g[k] = " << g[k]  << endl;
				return imp(); 
			} else if( d % 2 == 1 && g[k] != 2 ){
				// cout << "case 2: g[k] = " << g[k] << endl;
				return imp();
			}
		}
		if( k < (d+1)/2 && g[k] > 0 ){
			// cout << "case 3: g[k] = " << g[k] << ", " << k << endl;
			return imp();
		}
	}
	cout << "Possible" << endl;
	return 0;
}