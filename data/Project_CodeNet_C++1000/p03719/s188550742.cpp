#include <queue>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstdio>
#define rep(i, n) for(long long i = 0;(i) < (n);(i)++)
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	if (a <= c && c <= b)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}