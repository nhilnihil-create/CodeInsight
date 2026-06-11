#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int N = S.size();
	int n = 0;
	int w = 0;
	int s = 0;
	int e = 0;
	for( int i = 0; i < N; i++ ) {
		if( S[i] == 'N' ) n++;
		else if( S[i] == 'W' ) w++;
		else if( S[i] == 'S' ) s++;
		else if( S[i] == 'E' ) e++;
	}
	string ans = "Yes";
	if( n && s == 0 || n == 0 && s ) ans = "No";
	if( w && e == 0 || w == 0 && e ) ans = "No";

	cout << ans << endl;
}
