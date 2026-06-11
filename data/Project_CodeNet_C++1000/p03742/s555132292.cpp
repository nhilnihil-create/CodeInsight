#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <string>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define mp(a,b)	make_pair(a,b)
#define fst	first
#define scn second

int main() {
	ll x, y;	cin >> x >> y;
	if (max(x, y) - min(x, y) <= 1)	cout << "Brown" << endl;
	else	cout << "Alice" << endl;
	return 0;
}