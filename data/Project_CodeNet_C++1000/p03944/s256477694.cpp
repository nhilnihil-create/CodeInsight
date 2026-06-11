#include <bits/stdc++.h>
using namespace std;

int main()
{
	int W, H, N;
	cin >> W >> H >> N;
	vector<int> x( N );
	vector<int> y( N );
	vector<int> a( N );
	for( int i = 0; i < N; i++ ) {
		cin >> x[i] >> y[i] >> a[i];
	}

	vector<vector<int>> r( W, vector<int>( H ) );
	for( int i = 0; i < N; i++ ) {
		if( a[i] == 1 ) {
			for( int j = 0; j < x[i]; j++ ) {
				for( int k = 0; k < H; k++ ) {
					r[j][k] = 1;
				}
			}
		}
		else if( a[i] == 2 ) {
			for( int j = x[i]; j < W; j++ ) {
				for( int k = 0; k < H; k++ ) {
					r[j][k] = 1;
				}
			}
		}
		else if( a[i] == 3 ) {
			for( int j = 0; j < W; j++ ) {
				for( int k = 0; k < y[i]; k++ ) {
					r[j][k] = 1;
				}
			}
		}
		else if( a[i] == 4 ) {
			for( int j = 0; j < W; j++ ) {
				for( int k = y[i]; k < H; k++ ) {
					r[j][k] = 1;
				}
			}
		}
	}

	int ans = 0;
	for( int i = 0; i < W; i++ ) {
		for( int j = 0; j < H; j++ ) {
			if( r[i][j] == 0 ) ans++;
		}
	}

	cout << ans << endl;
}
