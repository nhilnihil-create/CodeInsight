#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int n;
	cin >> n;
	map<ll, int> mp;
	rep(i, n){
		ll a;
		cin >> a;
		mp[a]++;
	}
	int res = 0;
	for (auto x : mp) {
		if (x.second%2==1) res++;
	}
	cout << res << endl;
}