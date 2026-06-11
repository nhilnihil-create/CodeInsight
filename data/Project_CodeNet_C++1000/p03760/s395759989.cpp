#include <bits/stdc++.h>
using namespace std;

int main()
{
	string O, E;
	cin >> O >> E;

	int NO = O.size();
	int NE = E.size();
	string  ans;
	for( int i = 0; i < max( NO, NE ); i++ ) {
		ans += O[i];
		if( i >= NE ) continue;
		ans += E[i];
	}

	cout << ans << endl;
}
