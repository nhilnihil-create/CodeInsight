#include <bits/stdc++.h>
using namespace std;

int main(){
	char a, b;
	scanf(" %c %c", &a, &b);
	int x, y;
	x = (a == 'H') ? 1 : -1;
	y = (b == 'H') ? 1 : -1;
	if(x * y > 0) printf("H\n");
	else printf("D\n");
}
