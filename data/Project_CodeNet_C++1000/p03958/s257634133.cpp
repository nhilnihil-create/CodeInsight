#include <bits/stdc++.h>
using namespace std;

int main()
{
	int K, T;
	cin >> K >> T;
	vector<int> a( T );
	for( int i = 0; i < T; i++ ) {
		cin >> a[i];
	}

	int ma = *max_element( a.begin(), a.end() );
	int r = K - ma;
	int ans = max( 0, ma - r - 1 );

	cout << ans << endl;
}
