#include <bits/stdc++.h>

using namespace std;

#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)

#define LL long long
#define mp make_pair
#define pb push_back

#define K 601

int n, a[K], cnt[K];
int b[K * K];
int nid[K], pass[K];

int main() {
	scanf("%d", &n);
	FOE(i, 1, n) scanf("%d", &a[i]);
	FOE(i, 1, n) b[a[i]] = i;
	FOE(i, 1, n) nid[i] = i - 1, pass[i] = 0;

	FOE(i, 1, n * n) {
		if (b[i] != 0) {
			int tar = b[i];
			if (nid[tar] > 0) {
				puts("No");
				return 0;
			}
			
			pass[tar] = n - tar;
		} else {
			int ptr = 0;
			FOE(j, 1, n) if (nid[j] > 0 && (ptr == 0 || a[ptr] > a[j])) ptr = j;
			
			if (ptr) {
				nid[ptr]--;
				b[i] = ptr;
				
			} else {
				FOE(j, 1, n) if (pass[j] > 0) {
					ptr = j;
				}
				
				if (!ptr) {
					puts("No");
					return 0;	
				}
				
				pass[ptr]--;
				b[i] = ptr;
			}
		}
	}

	puts("Yes");
	FOE(i, 1, n * n) printf("%d ", b[i]);
	puts("");
}