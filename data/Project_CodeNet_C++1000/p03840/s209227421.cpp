#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

int main ()
{
	ll a[7];
	REP(i,7) cin >> a[i];

	ll ans = a[1];
	ll p0 = 0, p1 = 0;

	p0 += 2 * (a[0] / 2);
	p0 += 2 * (a[3] / 2);
	p0 += 2 * (a[4] / 2);

	if (a[0] > 0 && a[3] > 0 && a[4] > 0) {
		p1 += 3;
		a[0]--;
		a[3]--;
		a[4]--;
		p1 += 2 * (a[0] / 2);
		p1 += 2 * (a[3] / 2);
		p1 += 2 * (a[4] / 2);
	}

	cout << ans + max(p0, p1) << endl;
    
    return 0;
}
