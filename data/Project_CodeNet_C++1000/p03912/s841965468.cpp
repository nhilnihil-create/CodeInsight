#include<bits/stdc++.h>

using namespace std;


int main() {
	long long int N, M;
	cin >> N >> M;
	vector<long long int> mod( M ), sub( M );
	vector<long long int>data( 100001 );
	for( size_t i = 0; i < N; i++ ) {
		long long int X;
		cin >> X;
		data[X]++;
		mod[X%M]++;
	}
	long long int ans = 0;
	ans += mod[0] / 2;
	if( M % 2 == 0 ) {
		ans += mod[M / 2] / 2;
	}
	//cout << ans << endl;
	for( size_t i = 1; i < (M + 1) / 2; i++ ) {
		//cout << min( mod[i], mod[M - i] ) << endl;
		ans += min( mod[i], mod[M - i] );
		sub[i] = min( mod[i], mod[M - i] );
		sub[M - i] = min( mod[i], mod[M - i] );
	}
	for( size_t i = 0; i < M; i++ ) {
		//cout << sub[i] << " ";
	}
	//	cout << endl;
	for( size_t i = 0; i < 100001; i++ ) {
		if( i%M != 0 && (i%M) * 2 != M ) {
			if( data[i] % 2 == 1 && sub[i%M] > 0 ) {
				sub[i % M]--;
				data[i]--;
			}
		}
	}
	for( size_t i = 0; i < 100001; i++ ) {
		if( i%M && (i%M) * 2 != M ) {
			long long int xx = min( data[i], sub[i%M] );
			data[i] -= xx;
			sub[i%M] -= xx;
			ans += data[i] / 2;
		}
	}
	cout << ans << endl;
}