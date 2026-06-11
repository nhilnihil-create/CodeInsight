#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 500
int n, m;
int a[N][N];
bool b[N];
int c[N];

int cou(void) {
	int k, km;
	k = 0;
	km = 0;
	f(i, N)c[i] = 0;
	f(i, n) {
		f(j, m) {
			if (b[a[i][j]]) {
				c[a[i][j]]++;
				if (km < c[a[i][j]]) {
					km = c[a[i][j]];
					k = a[i][j];
				}
				break;
			}
		}
	}
	return k;
}





int main() {

	int x, ans;
	scanf("%d %d", &n,&m);
	f(i, n) {
		f(j, m) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	}
	f(i, N)b[i] = false;
	f(i, m)b[i] = true;
	ans = n;
	f(i,m){
		x = cou();
		ans = min(ans, c[x]);
		b[x] = false;
}

	printf("%d\n", ans);


	return 0;
}