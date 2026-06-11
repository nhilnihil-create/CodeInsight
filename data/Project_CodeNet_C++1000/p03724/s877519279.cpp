#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> c( N );
	for( int i = 0; i < M; i++ ) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		c[a]++;
		c[b]++;
	}

	string ans = "YES";
	for( int i = 0; i < N; i++ ) {
		if( c[i] % 2 ) {
			ans = "NO";
			break;
		}
	}

	cout << ans << endl;
}
