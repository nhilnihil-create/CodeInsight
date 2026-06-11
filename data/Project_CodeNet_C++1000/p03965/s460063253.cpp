#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio( false );

	string s;
	cin >> s;

	int result = 0;
	int p = 0;

	for( auto ch : s ) {
		if( ch == 'g' ) {
			if( p > 0 ) {
				p -= 1;
				result += 1;
			}
			else {
				p += 1;
			}
		}
		else if( ch == 'p' ) {
			if( p > 0 ) {
				p -= 1;
			}
			else {
				p += 1;
				result -= 1;
			}
		}
	}

	cout << result << endl;
}
