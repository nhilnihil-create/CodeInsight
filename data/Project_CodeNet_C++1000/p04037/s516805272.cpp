#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

bool cmp(int x, int y) {return x > y;}

int a[MAXN + 5], N;
int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + N + 1, cmp);
	for(int i=1;i<=N;i++) {
		if( a[i + 1] < i + 1 ) {
			int p = (a[i] - i) % 2, q;
			for(int j=i;j<=N+1;j++)
				if( a[j] < i ) {
					q = (j - i - 1) % 2;
					break;
				}
			puts(p & 1 || q & 1 ? "First" : "Second");
			break;
		}
	}
}