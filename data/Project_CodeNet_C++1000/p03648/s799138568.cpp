#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
typedef long long ll;
typedef long double ld;
 
const ll MOD = 1e9 + 7, INF = 1e18 + 1;
 
using namespace std;

ll k, n;

vector <ll> a;

ll check (vector <ll>& a)
{
	int x = 0;
	for (int i = 0; i < 50; i++)
		if (a[i] > a[x]) x = i;

	a[x] -= 50;

	if (a[x] < 0) return 0;

	for (int i = 0; i < 50; i++)
		if (x != i) a[i]++;

	return check (a) + 1;
}

int main ()
{
	cin >> k;

	cout << "50\n";

	for (int i = 0; i < 50; i++)
	{
		ll x = 49;

		if (i < k % 50) x = 50;
		else x = 49 - k % 50;
		x += k / 50;

		a.push_back (x);
		cout << x << ' ';
	}

	//cout << check (a);
}
