#include "bits/stdc++.h"
// "bits/stdc++.h"  " " cause i am using the precompiled header file
// i have already created the precompilede file in the directory
using namespace std;

#define GodSpeed ios_base::sync_with_stdio(false);cin.tie(NULL)

int main()
{
	GodSpeed;
	long long a, b, x;
	cin >> a >> b >> x;
	// long long count = 0;
	if (a % x == 0)
		cout << (b / x) - (a / x) + 1;
	else
		cout << (b / x) - (a / x);

	return 0;
}