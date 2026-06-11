#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

const int bound = 5050;
bool dp[bound][bound];

void init(){
	for( int i = 0; i < bound; ++i ){
		for( int j = 0; j < bound; ++j ){
			dp[i][j] = false;
		}
	}
}

int main(){
	int n, k; cin >> n >> k; 
	vector<int> a(n);
	for( auto &k : a ) cin >> k;
	sort( a.begin(), a.end() );
	int ok = -1, ng = lower_bound( a.begin(), a.end(), k ) - a.begin();
	int target;
	while( abs(ok-ng) > 1 ){
		init();
		dp[0][0] = true;
		target = (ok+ng)/2;
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j <= 5000; ++j ){
				dp[i+1][j] = dp[i][j];
				if( i == target ) continue;
				if( j >= a[i] ) dp[i+1][j] |= dp[i][j-a[i]];
			}
		}
		bool flag = false;
		for( int j = k-a[target]; j < k; ++j ){
			if( dp[n][j] ) flag = true; 
		}
		if( flag ){
			ng = target;
		} else {
			ok = target;
		}
	}
	cout << ok+1 << endl;
}
