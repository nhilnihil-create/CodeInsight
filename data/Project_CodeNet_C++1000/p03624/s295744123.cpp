#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	string ans = "None";
	for( char a = 'a'; a <= 'z'; a++ ) {
		if( S.find( a ) == string::npos ) {
			ans = string( 1, a );
			break;
		}
	}

	cout << ans << endl;
}
