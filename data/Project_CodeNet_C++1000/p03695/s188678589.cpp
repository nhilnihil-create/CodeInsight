#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a( N );
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
	}

	vector<int> color( 9 );
	for( int i = 0; i < N; i++ ) {
		int aa = a[i];
		if( aa < 400 ) color[0]++;
		else if( aa < 800 ) color[1]++;
		else if( aa < 1200 ) color[2]++;
		else if( aa < 1600 ) color[3]++;
		else if( aa < 2000 ) color[4]++;
		else if( aa < 2400 ) color[5]++;
		else if( aa < 2800 ) color[6]++;
		else if( aa < 3200 ) color[7]++;
		else color[8]++;
	}
	int mi = 0;
	for( int i = 0; i < 8; i++ ) {
		if( color[i] ) mi++;
	}
	int ma = mi + color[8];
	if( mi == 0 ) mi = 1;

	cout << mi << " " << ma << endl;
}
