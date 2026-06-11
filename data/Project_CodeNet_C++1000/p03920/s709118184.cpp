#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int s = sqrt( N * 2 );
	int sum = s * (s + 1) / 2;
	int n;
	for( n = s; sum < N; n++ ) {
		sum = n * (n + 1) / 2;
	}
	if( sum > N && n * (n - 1) / 2 - N >= 0 ) n--;
	sum = n * (n + 1) / 2;
	int r = sum - N;

	for( int i = 1; i <= n; i++ ) {
		if( i == r ) continue;
		cout << i << endl;
	}
}