#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ans = 0;
	bool flag = false;
	for(int i = a; i <= b; i++) {
		if(i >= c && i <= d) {
			ans++;
			flag = true;
		}
	}
	printf("%d\n", ans - flag);
}
