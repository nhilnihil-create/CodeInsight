#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	priority_queue<long long> que;
	for( int i = 0; i < N * 3; i++ ) {
		long long a;
		cin >> a;
		que.push( a );
	}

	long long ans = 0;
	for( int i = 0; i < N; i++ ) {
		que.pop();
		long long a = que.top();
		que.pop();
		ans += a;
	}

	cout << ans << endl;
}
