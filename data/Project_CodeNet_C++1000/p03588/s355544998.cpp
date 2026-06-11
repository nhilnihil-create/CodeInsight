#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int N;
	cin >> N;
	vector<pair<int, int>> A( N );
	for( auto& v: A ) { cin >> v.first >> v.second; }
	sort( A.begin(), A.end() );

	cout << A.back().first + A.back().second << endl;

	return 0;
}
