#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	int n; cin >> n;
	ll Tnow, Anow;
	Tnow = Anow = 1;
	rep(i, 1, n)
	{
		ll t, a; cin >> t >> a;
		ll x = max((Tnow + t - 1) / t, (Anow + a - 1) / a);
		Tnow = t * x;
		Anow = a * x;
	}
	cout << Tnow + Anow << endl;
}
