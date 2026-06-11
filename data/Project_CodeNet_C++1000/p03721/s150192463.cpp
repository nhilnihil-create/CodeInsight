#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	ll num, target;
	cin >> num >> target;
	vector<pair<ll, ll>> a(num);
	rep(i, num)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	ll distance = target;

	rep(i, num)
	{
		if (a[i].second < distance)
		{
			distance -= a[i].second;
		}
		else
		{
			cout << a[i].first << endl;
			return 0;
		}
	}
	return 0;
}