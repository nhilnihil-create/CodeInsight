#include <cstdio>
#include <algorithm>

#define Rep(i, n) for (int i = 1; i <= n; i ++)

using namespace std;

const int N = 100010;

int a[N], g0[N], g1[N];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b);}

int main()
{
	int n;
	long long sum = 0;
	scanf("%d", &n);
	Rep(i, n){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	if (!(n & 1)) {
		if (sum & 1) printf("First\n");
		else printf("Second\n");
	}
	else {
		if (!(sum & 1)) printf("First\n");
		else {
			int tid = 0, tmp;
			while (true){
				tid ++, sum = 0;
				bool f0 = false;
				Rep(i, n){
					g0[i] = gcd(g0[i - 1], a[i]), sum += a[i];
					if (a[i] == 1) f0 = true; 
				}
				if (f0) break;
				for (int i = n; i; i --) g1[i] = gcd(g1[i + 1], a[i]);
				bool flag = false;
				Rep(i, n) {
					tmp = gcd(gcd(g0[i - 1], g1[i + 1]), a[i] - 1);
					if (((sum - 1) / tmp) & 1){
						a[i] --, flag = true;
						break;
					}
				}
				if (!flag) break;
				else Rep(i, n) a[i] /= tmp;
			}
			if (!(tid & 1)) printf("First\n");
			else printf("Second\n");
		}
	}
	
	return 0;
}