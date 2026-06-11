#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, a, b;
	scanf("%d%d%d", &x, &a, &b);
	if(b > a + x) printf("dangerous\n");
	else if(b <=  a) printf("delicious\n");
	else printf("safe\n");
}
