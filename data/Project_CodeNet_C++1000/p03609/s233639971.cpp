#include <bits/stdc++.h>
using namespace std;

signed main(){
	int X, t;
	scanf("%d%d", &X, &t);
	printf("%d\n", max(0, X - t));
	return 0;
}