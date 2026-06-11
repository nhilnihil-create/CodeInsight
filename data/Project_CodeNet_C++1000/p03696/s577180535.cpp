#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	int cnt = 0;
	int ma = 0;
	for( int i = 0; i < N; i++ ) {
		if( S[i] == ')' ) cnt++;
		else cnt--;
		if( cnt > ma ) ma = cnt;
	}
	string ans;
	if( ma > 0 ) ans += string( ma, '(' );
	ans += S;
	N = ans.size();
	cnt = 0;
	ma = 0;
	for( int i = N - 1; i >= 0; i-- ) {
		if( ans[i] == '(' ) cnt++;
		else cnt--;
		if( cnt > ma ) ma = cnt;
	}
	if( ma > 0 ) ans += string( ma, ')' );

	cout << ans << endl;
}
