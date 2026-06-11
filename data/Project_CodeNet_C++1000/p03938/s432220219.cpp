#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> p( N );
	for( int i = 0; i < N; i++ ) {
		cin >> p[i];
		p[i]--;
	}

	vector<int> a( N );
	vector<int> b( N );
	for( int i = 0; i < N; i++ ) {
		if( i == 0 ) {
			a[ p[i] ] = 1000000000 / 2;
			b[ p[i] ] = 1000000000 / 2;
		}
		else {
			int d = (p[i] - p[i - 1]) * N;
			a[ p[i] ] = a[ p[i - 1] ] + d;
			b[ p[i] ] = b[ p[i - 1] ] - d;
		}
	}
	for( int i = 0; i < N; i++ ) {
		a[ p[i] ] += i;
	}

	for( int i = 0; i < N; i++ ) {
		if( i ) cout << " ";
		cout << a[i];
	}
	cout << endl;
	for( int i = 0; i < N; i++ ) {
		if( i ) cout << " ";
		cout << b[i];
	}
	cout << endl;
}
