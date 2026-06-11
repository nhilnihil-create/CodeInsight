#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	long ans = -1;
	bool flag = false;
	int now, pre = a[n-1];
	for(int i = n - 2; i >= 0; i--) {
		now = a[i];
		if(pre == now) {
			ans *= now;
			if(flag) break;
			flag = true;
			i--;
			pre = a[i];
		}else{
			pre = now;
		}
	}
	printf("%ld\n", (ans == -1) ? 0 : -ans);
}
