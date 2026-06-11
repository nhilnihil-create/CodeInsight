#include <bits/stdc++.h>
using namespace std;

signed main(){
	int x, y;
	int g[13] = {-1, 0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0};
	scanf("%d%d", &x, &y);
	if(g[x] == g[y]){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}