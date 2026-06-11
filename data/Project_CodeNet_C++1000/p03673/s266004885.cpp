#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a( n );
	for( int i = 0; i < n; i++ ) {
		cin >> a[i];
	}

	deque<int> b;
	for( int i = 0; i < n; i++ ) {
		if( i % 2 ) b.push_front( a[i] );
		else b.push_back( a[i] );
	}
	if( n % 2 ) reverse( b.begin(), b.end() );

	for( int i = 0; i < n; i++ ) {
		if( i ) cout << " ";
		cout << b[i];
	}
	cout << endl;
}
