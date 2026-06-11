#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N;
	vector<int> T( N );
	for( int i = 0; i < N; i++ ) {
		cin >> T[i];
	}
	cin >> M;
	typedef pair<int, int> P;
	vector<P> PX( M );
	for( int i = 0; i < M; i++ ) {
		int p, x;
		cin >> p >> x;
		p--;
		PX[i] = P( p, x );
	}

	for( int i = 0; i < M; i++ ) {
		int p, x;
		tie( p, x ) = PX[i];
		long long ans = 0;
		for( int j = 0; j < N; j++ ) {
			if( j == p ) ans += x;
			else ans += T[j];
		}
		cout << ans << endl;
	}
}
