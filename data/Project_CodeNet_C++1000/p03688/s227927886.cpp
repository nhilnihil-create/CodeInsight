#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int a[100005];
int main() {
	int n;
	cin>>n;
	int maxx = 0, minn = n + 1;
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
		maxx = max(maxx, a[i]);
		minn = min(minn, a[i]);
	}
	if (maxx > minn + 1)
		return puts("No"), 0;
	if (maxx == minn) {
		if (minn == n - 1)
			return puts("Yes"), 0;
		if ( (minn << 1) <= n)
			return puts("Yes"), 0;
		else
			return puts("No"), 0;
	} else {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += (a[i] == minn);
		if (minn < cnt)
			return puts("No"), 0;
		if (n - cnt < ((maxx - cnt) << 1) )
			return puts("No"), 0;
		else
			return puts("Yes"), 0;
	}
}