#include <bits/stdc++.h>
using namespace std;

int main()
{
	string w;
	cin >> w;

	int N = w.size();
	map<char, int> mp;
	for( int i = 0; i < N; i++ ) {
		mp[ w[i] ]++;
	}
	string ans = "Yes";
	for( auto it = mp.begin(); it != mp.end(); it++ ) {
		if( it->second % 2 ) {
			ans = "No";
		}
	}

	cout << ans << endl;
}
