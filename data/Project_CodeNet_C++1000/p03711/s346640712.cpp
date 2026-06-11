#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int x, y;
	switch(a) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: x = 1; break;
	case 4:
	case 6:
	case 9:
	case 11: x = 2; break;
	case 2: x = 3; break;
	}
	switch(b) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: y = 1; break;
	case 4:
	case 6:
	case 9:
	case 11: y = 2; break; break;
	case 2: y = 3; break;
	}
	if(x == y) printf("Yes\n");
	else printf("No\n");
}
