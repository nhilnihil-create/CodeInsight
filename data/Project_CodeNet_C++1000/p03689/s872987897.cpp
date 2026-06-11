#include <cstdio>
#include <algorithm>
#include <vector>

#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define mp(a, b) make_pair(a, b)

using namespace std;

int a[510][510];

int main()
{
	int H, W, h, w;
	scanf("%d%d%d%d", &H, &W, &h, &w);
	long long sum = 0;
	int tmp0 = (1e9 - 1) / (h * w - 1), tmp1 = -tmp0 * (h * w - 1) - 1;
	
	Rep(i, H) Rep(j, W){
		if (!(i % h) && !(j % w)) a[i][j] = tmp1;
		else a[i][j] = tmp0;
		sum += a[i][j];
	}
	if (sum <= 0) printf("No\n");
	else {
		printf("Yes\n");
		Rep(i, H){
			Rep(j, W) printf("%d ", a[i][j]);
			printf("\n");
		}
	}
	
	return 0;
}