#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> g(n, 0);
	q *= 2;
	while( q-- ){
		int x; cin >> x; --x; ++g[x];
	}
	for( auto k : g ){
		if( k % 2 == 1 ){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}