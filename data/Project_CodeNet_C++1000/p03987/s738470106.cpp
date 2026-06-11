#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> pos( N + 1 );
	for( int i = 0; i < N; i++ ) {
		int a;
		cin >> a;
		pos[a] = i + 1;
	}

	set<int> st;
	st.insert( 0 );
	st.insert( N + 1 );
	long long ans = 0;
	for( int i = 1; i < N + 1; i++ ) {
		long long ii = pos[i];
		auto pa = st.insert( ii );
		auto it = pa.first;
		long long l = *prev( it );
		long long r = *next( it );
		ans += ( ii - l ) * ( r - ii ) * i;
	}

	cout << ans << endl;
}
