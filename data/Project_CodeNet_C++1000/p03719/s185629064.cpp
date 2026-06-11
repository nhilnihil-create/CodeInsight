// ABC_061_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if(a<=c && c<=b) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}