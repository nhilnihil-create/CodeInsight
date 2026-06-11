#include <bits/stdc++.h>
using namespace std;

signed main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(a + b + c == 2 * max(a, max(b, c))){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}