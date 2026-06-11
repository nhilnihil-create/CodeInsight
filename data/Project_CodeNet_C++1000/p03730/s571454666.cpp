#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	string ans = "NO";
	for( int i = 1; i < 100000; i++ ) {
		if( A * i % B == C ) {
			ans = "YES";
			break;
		}
	}

	cout << ans << endl;
}
