#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B;
	scanf("%d%d", &A, &B);
	if(A + B >= 10){
		printf("error\n");
	}
	else{
		printf("%d\n", A + B);
	}
	return 0;
}