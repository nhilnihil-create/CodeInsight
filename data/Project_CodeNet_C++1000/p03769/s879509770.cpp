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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main(){
	int a[200];
	long long k, x, y, z;
	int s, ans;
	scanf("%lld", &k);
	f(i, 200)a[i] = -1;
	f(i, 100)a[i] = i;
	f(i, 100){
		if (k > 0){
			x = 1;
			y = 0;
			f(j, i){
				x = x * 2;
				if (x <= k)y++;
				else {
					x = x / 2;
					break;
				}
			}
			f(j, 99 - y)a[199 - j] = a[198 - j];
			a[100 + y] = i;
			k -= x;
			if (k == 0)break;
		}
	}
	s = 0;
	f(i, 200){
		if (a[i] >= 0){
			s++;
			a[i]++;
		}
	}
  printf("%d\n",s);
	f(i, s){
		printf("%d", a[i]);
		if (i < s - 1)printf(" ");
		else printf("\n");
	}

	return 0;
}
