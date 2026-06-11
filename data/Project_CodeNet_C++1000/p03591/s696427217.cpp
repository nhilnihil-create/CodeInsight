#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	string S;
	cin >> S;
	cout << (S.size() >= 4 && S.find( "YAKI" ) == 0 ? "Yes" : "No") << endl;

	return 0;
}
