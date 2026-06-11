#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string s, t;
	cin >> N >> s >> t;

	int ans = N * 2;
	for( int i = 0; i < N; i++ ) {
		string sub = s.substr( i, N - i );
		if( sub == t.substr( 0, N - i ) ) {
			ans = i + N;
			break;
		}
	}

	cout << ans << endl;
}
