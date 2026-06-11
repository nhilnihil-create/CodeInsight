#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	typedef pair<long long, long long> P;
	vector<P> AB( N );
	for( int i = 0; i < N; i++ ) {
		long long A, B;
		cin >> A >> B;
		AB[i] = P( A, B);
	}

	sort( AB.begin(), AB.end() );
	long long ans = AB[0].first;
	ans += AB[N - 1].first - AB[0].first + AB[N - 1].second;

	cout << ans << endl;
}
