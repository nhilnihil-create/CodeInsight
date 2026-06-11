#include <bits/stdc++.h>
using namespace std;

signed main(){
	int x, a, b;
	scanf("%d%d%d", &x, &a, &b);
	if(abs(a - x) < abs(b - x)){
		printf("A\n");
	}
	else{
		printf("B\n");
	}
	return 0;
}