#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int x, y, z;
	int ans = 0;
	while(true) {
		if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
			ans++;
		else break;
		if(a == b && b == c && c == a) {
			ans = -1;
			break;
		}
		x = a, y = b, z = c;
		a = (y + z) / 2;
		b = (x + z) / 2;
		c = (x + y) / 2;
	}
	printf("%d\n", ans);
}
