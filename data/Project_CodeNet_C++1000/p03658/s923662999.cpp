#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long int ll;


int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end(),greater<int>());
	ll ans = 0;
	for (int i = 0; i < k; i++) {
		ans += num[i];
	}
	cout << ans << endl;
	return 0;
}