#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	map<long long, int> mp;
	for( int i = 0; i < N; i++ ) {
		if( mp[ A[i] ] ) mp[ A[i] ] = 0;
		else mp[ A[i] ] = 1;
	}

	int ans = 0;
	for( auto it = mp.begin(); it != mp.end(); it++ ) {
		if( it->second ) ans++;
	}
	cout << ans << endl;
}
