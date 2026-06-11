#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cassert>

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define PI acos(-1.0)

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef vector <ll> vll;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll k;
	cin >> k;
	vll vec;
	ll all = k / 50;
	for (int i = 0; i < 50; i++) vec.push_back(49 + all);	
	ll m = k % 50;
	if (m != 0) {
		for (int i = m; i < 50; i++) vec[i] -= m;
		for (int i = 0; i < m; i++) vec[i] += 50 - (m - 1);
	}
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	cout << endl;
	return 0;
}
