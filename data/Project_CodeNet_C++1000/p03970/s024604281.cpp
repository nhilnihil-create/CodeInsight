#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	string S;
	cin >> S;

	string t = "CODEFESTIVAL2016";
	int ans = 0;
	for( int i = 0; i < S.size(); ++i ) {
		ans += S[i] != t[i];
	}

	cout << ans << endl;
	
	return 0;
}
