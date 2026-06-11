#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <string>
#include <queue>
#include <map>
#include <stack>
#define inf 0x7fffffff
#define int long long

using namespace std;

int n, a[2000005], l[2000005], r[2000005];
stack<int> s;

signed main(void) {
	scanf("%lld", &n);
	for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
	for(int i=1; i<=n; i++) {
		while(!s.empty() && a[s.top()]>=a[i]) s.pop();
		l[i] = s.empty() ? (i) : (i-s.top());
		s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i=n; i>=1; i--) {
		while(!s.empty() && a[s.top()]>=a[i]) s.pop();
		r[i] = s.empty() ? (n-i+1) : (s.top()-i);
		s.push(i);
	}
	int ans = 0;
	for(int i=1; i<=n; i++) ans += (l[i]*r[i])*a[i]/*, cout<< l[i]<< ' '<< r[i]<< '\n'*/;
	cout<< ans<< '\n';
} 