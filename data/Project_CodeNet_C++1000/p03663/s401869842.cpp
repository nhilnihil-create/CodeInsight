/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;
const ll X = 1e5 - 1;

int main()
{
	ll l = 2, r = 1e9, temp = 10;
	while (l <= r)
	{
		cout << "? " << temp << endl;
		char c;
		cin >> c;
		if (c == 'Y')
		{
			l = temp + 1;
			temp *= 10;
		}

		else
		{
			r = temp - 1;
			break;
		}
	}

	--l;
	ll st = l;
	while (l < r)
	{
		ll mid = (l + r) / 2;
		cout << "? " << mid << X << endl;
		char c;
		cin >> c;
		if (c == 'Y')
			r = mid;
		else
			l = mid + 1;
	}

	if (l > st)
	{
		cout << "! " << l << endl;
		return 0;
	}

	vector <ll> v;
	for (temp = 1; temp <= st; temp *= 10)
		v.pb(temp);

	int n = v.size();
	l = 0, r = n - 1;
	while (l < r)
	{
		int mid = (l + r) / 2;
		cout << "? " << 2 * v[mid] << endl;
		char c;
		cin >> c;
		if (c == 'Y')
			r = mid;
		else
			l = mid + 1;
	}

	cout << "! " << v[l] << endl;
	return 0;
}