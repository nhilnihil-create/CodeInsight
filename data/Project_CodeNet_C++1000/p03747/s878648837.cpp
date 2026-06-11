#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];

int main(){
	int n, len, t, dir, cnt;
	scanf("%d %d %d",&n,&len,&t);
	cnt = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d %d",&a[i],&dir);
		a[i] += (dir == 1 ? t : -t);
		cnt += a[i] / len;
		if (a[i] % len < 0) cnt--;
		a[i] = (a[i] % len + len) % len;
	} 
	sort(a + 1, a + n + 1);
	cnt = (cnt % n + n) % n;
	for (int i = cnt + 1; i <= n; i++) printf("%d\n", a[i]);
	for (int i = 1; i <= cnt; i++) printf("%d\n", a[i]);
	return 0;
}