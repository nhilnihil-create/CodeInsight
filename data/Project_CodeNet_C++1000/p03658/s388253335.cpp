#ifdef __unix__
#include <bits/stdc++.h>
#else
#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>
#endif

#define fastIO ios_base::sync_with_stdio(0), cin.tie(NULL)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mkp make_pair
/*#define NUMTOSTR(x)  (unsigned char)((x) + 48);*/
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long  ull;
using namespace std;

int main() {
	fastIO;
	int x, y;
	cin >> x >> y;
	vector<int> v(x);
	for (int i = 0; i < x; i++) cin >> v[i];
	int sum = 0;
	sort(all(v));
	for (int i = x - 1; i >= x - y; i--) sum += v[i];
	cout << sum;
	return 0;
}