#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n, m, a[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m; ++i)
		scanf("%d", &a[i]);
	int cnt = 0;
	for(int i = 1;i <= m; ++i) 
		if(a[i] & 1)
			cnt++;
	if(cnt > 2) return 0 * puts("Impossible");
	cnt = 0;
	for(int i = 1;i <= m; ++i) {
		if(a[i] & 1) {
			cnt++;
			if(cnt == 1) swap(a[1], a[i]);
			if(cnt == 2) {
				swap(a[m], a[i]);
				break;
			}
		}
	}
	for(int i = 1;i <= m; ++i)
		printf("%d ", a[i]);
	puts("");
	if(m == 1 && a[1] > 1) m = 2, a[2] = 1, a[1]--;
	else if(m == 1 && a[1] == 1) m = 1;
	else if(a[m] == 1) m--, a[1]++;
	else a[m]--, a[1]++;
	printf("%d\n", m);
	for(int i = 1;i <= m; ++i)
		printf("%d ", a[i]);
	puts("");
	return 0;
}