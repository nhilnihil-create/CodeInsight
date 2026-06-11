#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

int main( int argc, char *argv[] ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout << ( b - a == c - b ? "YES" : "NO" ) << "\n";

	return 0;
}
