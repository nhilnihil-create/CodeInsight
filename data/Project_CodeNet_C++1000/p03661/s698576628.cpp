#include <iomanip>
#include <random>
#include <time.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;
int main()
{	
	long long int n, a[200020], b = 0, c = 0, ans;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1)b = a[1];
		else c += a[i];
	}
	ans = abs(b - c);
	for (int i = 2; i < n; i++) {
		b += a[i];
		c -= a[i];
		ans = min(ans, abs(b - c));
	}
	cout << ans << endl;
}