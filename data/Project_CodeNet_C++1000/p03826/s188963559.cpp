#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B, C, D;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	printf("%d\n", max(A * B, C * D));
	return 0;
}