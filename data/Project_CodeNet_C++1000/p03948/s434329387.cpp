#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], n, t;
int main() {
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", a + i);
	int m = 0, now = -1, cnt = 0;
	for(int i = n; i; -- i) {
		m = max(m, a[i]);
		int dif = m - a[i];
		// cerr << i <<" " << dif
		if(dif > now)
			now = dif, cnt = 1;
		else if(dif == now)
			++ cnt;
	}
	printf("%d\n", cnt);
}