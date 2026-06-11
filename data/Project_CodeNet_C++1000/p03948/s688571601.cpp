#include<cstdio>
#include<algorithm>
using namespace std;

int n, t;
int a[111111];

int main() {
	scanf("%d%d", &n, &t);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	int ma = a[n-1];
	int gap = 0, cnt = 0;
	for(int i=n-2;i>=0;i--) {
		if (ma - a[i] > gap) {
			gap = ma - a[i];
			cnt = 1;
		} else if (ma - a[i] == gap) {
			cnt++;
		}
		
		ma = max(ma, a[i]);
	}
	printf("%d\n", cnt);
	
	return 0;
}