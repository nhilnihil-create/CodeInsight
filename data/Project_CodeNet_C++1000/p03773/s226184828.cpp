#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	a += b;
	if(a >= 24) a -= 24;
	printf("%d\n", a);
}
