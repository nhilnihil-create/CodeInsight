#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;

typedef long long ll ;
#define rep(i , n ) for ( int i =0; i < n ; i++)
#define _sort(arg) sort(begin(arg), end(arg))
#define MOD 1000000007
#define pb push_back
#define DEBUG(x) cout << #x << ": " << x << endl;

#define MAX 500000

int N, K;
int a[MAX];

int main() {
	cin >> N >> K;
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
	}

	sort( a, a + N );
	int t = 0;
	int ans = N;
	for( int i = N - 1; i >= 0; i-- ) {
		if( t + a[i] < K ) {
			t += a[i];
		}
		else {
			ans = min( ans, i );
		}
	}

	cout << ans << endl;

	return 0;
}

