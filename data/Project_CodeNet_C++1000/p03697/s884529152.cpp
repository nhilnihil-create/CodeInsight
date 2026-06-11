// ABC_063_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int main()
{
	int a, b;
	cin >> a >> b;

	if(a+b >= 10) cout << "error" << "\n";
	else cout << a+b << "\n";

	return 0;
}