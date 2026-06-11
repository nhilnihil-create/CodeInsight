#include<functional>
#include <algorithm>
#include  <iostream>
#include   <ctype.h>
#include   <cstring>
#include   <fstream>
#include    <cstdio>
#include    <vector>
#include    <string>
#include     <cmath>
#include     <deque>
#include     <stack>
#include     <queue>
#include      <list>
#include       <set>
#include       <map>
#define INF 0X7FFFFFFF
#define PI acos(-1.0)
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
inline int getint()
{
	int w = 0, q = 0;
	char c = getchar();
	while ((c<'0' || c>'9') && c != '-') c = getchar();
	if (c == '-') q = 1, c = getchar();
	while (c >= '0'&&c <= '9') w = w * 10 + c - '0', c = getchar();
	return q ? -w : w;
}
int n;
ll a[100005];
char c[100005];
int main() {
	n = getint();
	int i = 0;
	ll ans = 0;
	ll sum = 0;
	while (i < n) {
		a[i] = getint();
		sum += a[i];
		if (i != 0 && c[i - 1] == '-') {
			ans -= a[i];
		}
		else {
			ans += a[i];
		}
		if (i == n - 1) {
			break;
		}
		c[i] = getchar();
		i++;
	}
	int flag = 1;
	ll t = ans;
	ll m = sum;
	for (int i = 0; i < n - 1; i++) {
		if (c[i] == '-') {
			sum = m;
			m -= a[i + 1] * 2;
			sum -= a[i + 1] * 2;
			int j = i + 1;
			while (j < n) {
				if (c[j] == '+') {
					sum -= a[j + 1] * 2;
					j++;
				}
				else {
					break;
				}
			}
			t = max(t, sum);
		}
	}
	ans = max(t, ans);
	cout << ans << endl;
	return 0;
}