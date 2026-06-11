#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> ans( N );
	for( int i = 0; i < M; i++ ) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		ans[a]++;
		ans[b]++;
	}

	for( int i = 0; i < N; i++ ) {
		cout << ans[i] << endl;
	}
}
