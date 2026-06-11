#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, t;
	scanf("%d%d", &x, &t);
	if(x <= t) printf("0\n");
	else printf("%d\n", x - t);
}
