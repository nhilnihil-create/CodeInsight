#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;


int main() {
	ll x;
	cin >> x;
	ll now = 0;
	ll cnt = 1;
	while (now < x)
		now += cnt, ++cnt;
	--cnt;
	cout << cnt << "\n";
	return 0;
}


