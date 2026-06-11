#include <bits/stdc++.h>
using namespace std;

signed main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", a + b + c - max({a, b, c}));
	return 0;
}