#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> s( N );
	for( int i = 0; i < N; i++ ) {
		cin >> s[i];
	}

	sort( s.begin(), s.end() );
	int ans = accumulate( s.begin(), s.end(), 0 );
	if( ans % 10 == 0 ) {
		for( int i = 0; i < N; i++ ) {
			if( s[i] % 10 ) {
				ans -= s[i];
				break;
			}
		}
	}
	if( ans % 10 == 0 ) ans = 0;

	cout << ans << endl;
}
