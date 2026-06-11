#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int N;
long long a[MAX * 3];

long long sumL[MAX + 1];
long long sumR[MAX + 1];
priority_queue< long long, vector< long long >, greater< long long > > queL;
priority_queue< long long, vector< long long > > queR;


int main()
{
	cin >> N;
	for( int i = 0; i < N * 3; i++ ) {
		cin >> a[i];
	}

	for( int i = 0; i < N; i++ ) {
		queL.push( a[i] );
		sumL[0] += a[i];
	}
	for( int i = 0; i < N; i++ ) {
		int n = N + i;
		queL.push( a[n] );
		long long s = queL.top();
		queL.pop();
		sumL[i + 1] = sumL[i] + a[n] - s;
	}
	for( int i = 0; i < N; i++ ) {
		int n = N * 2 + i;
		queR.push( a[n] );
		sumR[0] += a[n];
	}
	for( int i = 0; i < N; i++ ) {
		int n = N * 2 - i - 1;
		queR.push( a[n] );
		long long s = queR.top();
		queR.pop();
		sumR[i + 1] = sumR[i] + a[n] - s;
	}
	reverse( sumR, sumR + N + 1 );
	long long ans = INT64_MIN;
	for( int i = 0; i < N + 1; i++ ) {
		ans = max( ans, sumL[i] - sumR[i] );
	}

	cout << ans << endl;

	return 0;
}
