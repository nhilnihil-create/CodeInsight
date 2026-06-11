#include <iostream>
#include <cstdio>
#include <limits.h>
#define N 100005

using namespace std;

int n;
int a[N], Min, Max;

inline void read(int &x) {
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

int main() {
	read(n);
	Min = INT_MAX, Max = INT_MIN;
	for(int i = 1; i <= n; ++i)	{
		read(a[i]);
		Min = min(Min, a[i]);
		Max = max(Max ,a[i]);
	}
	if(Max - Min > 1) {
		puts("No");
	} else if(Max == Min) {
		if(Max == n - 1 || a[1] * 2 <= n) {
			puts("Yes");
		} else {
			puts("No");
		}
	} else {
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			if(a[i] == Max) ++cnt;
		if(Max - (n - cnt) > 0 && (Max - (n - cnt)) * 2 <= cnt) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}