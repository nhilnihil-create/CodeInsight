#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,m,n) for(int i=m;i<n;i++)
#define endre getchar(); getchar();return 0;
int a[200010];
int sa[200010];
signed main() {
	int n;
	cin >> n;
	int s=0, d=0;
	rep(i, n) {
		cin >> a[i];
		d += a[i];
	}
	rep(i, n-1) {
		s += a[i];
		d -= a[i];
		sa[i] = abs(s - d);
	}
	sort(sa, sa + n-1);
	cout << sa[0] << endl;
}