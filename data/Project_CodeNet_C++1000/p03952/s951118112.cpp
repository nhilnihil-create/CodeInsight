#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, x;
	cin >> N >> x;

	string ans = "No";
	int n = 2 * N - 1;
	vector<int> v( n );
	if( 1 < x && x < n ) {
		ans = "Yes";
		if( N == 2 ) {
			for( int i = 0; i < n; i++ ) v[i] = i + 1;
		}
		else {
			int n2 = n / 2;
			if( x == 2 ) {
				v[n2 - 1] = x + 1;
				v[n2] = x;
				v[n2 + 1] = x - 1;
				v[n2 + 2] = x + 2;
				int j = 1;
				for( int i = 0; i < n2 - 1; i++ ) {
					if( j == x - 1 ) j = x + 3;
					v[i] = j;
					j++;
				}
				for( int i = n2 + 3; i < n; i++ ) {
					if( j == x - 1 ) j = x + 3;
					v[i] = j;
					j++;
				}
			}
			else {
				v[n2 - 1] = x - 1;
				v[n2] = x;
				v[n2 + 1] = x + 1;
				v[n2 + 2] = x - 2;
				int j = 1;
				for( int i = 0; i < n2 - 1; i++ ) {
					if( j == x - 2 ) j = x + 2;
					v[i] = j;
					j++;
				}
				for( int i = n2 + 3; i < n; i++ ) {
					if( j == x - 2 ) j = x + 2;
					v[i] = j;
					j++;
				}
			}
		}
	}

	cout << ans << endl;
	if( ans == "Yes" ) {
		for( int i = 0; i < n; i++ ) {
			cout << v[i] << endl;
		}
	}
}
