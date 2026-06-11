#include <bits/stdc++.h>
using namespace std;

int main(){
	int w, a, b;
	scanf("%d%d%d", &w, &a, &b);
	if(a + w < b) printf("%d\n", b - a - w);
	else if(b + w < a) printf("%d", a - b - w);
	else printf("%d\n", 0);
}
