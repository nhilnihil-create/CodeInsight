#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int sum[100010];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int q, w;
		scanf("%d %d", &q, &w);
		sum[q]++;
		sum[w+1]--;
		int pre = q;
		for (int y = 2; y <= sqrt(w); y++) {
			int st = q / y;
			if (q%y)
				st++;
			int en = w / y;
			sum[st]++;
			sum[min(en + 1, pre)]--;
			pre = st;
		}
		int x = sqrt(w);
		for (int y = 1; y <= min(x,pre-1); y++) {
			int st = q / y;
			if (q%y)
				st++;
			st *= y;
			if (q <= st && st <= w) {
				sum[y]++;
				sum[y + 1]--;
			}
		}
	}
	int dap = 0;
	for (int i = 1; i <= m; i++) {
		dap += sum[i];
		printf("%d\n",dap);
	}
}