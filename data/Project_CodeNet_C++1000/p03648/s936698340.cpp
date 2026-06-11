#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;
#define fname ""
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define inf 1000000000
#define INF 1000000000000000000ll
const int N = 500;
int n;
ll a[N], k;

void inc() {
	int id = 1;
	for (int i = 2; i <= n; ++ i) {
		if (a[id] > a[i]) id = i;
	}

	a[id] += n;
	for (int i = 1; i <= n; ++ i) {
		if (id != i) a[i]--;
	}
}

int main() {
	
	cin >> k;
	
	n = 50;
	ll mn = k / n;
	
	for (int i = 1; i <= n; ++ i) {
		a[i] = mn + i - 1;
	}

	k %= n;

	for (int i = 1; i <= k; ++ i) inc();

	cout << n << endl;
	for (int i = 1; i <= n; ++ i) cout << a[i] << " ";
        
    return 0;
}
