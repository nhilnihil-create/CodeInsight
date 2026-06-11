#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int x[N], w[N], ans[N], n, m, t;
long long mi;
int main() {
	scanf("%d%d%d", &n, &m, &t);
	for(int i=1; i<=n; i++) { scanf("%d%d", &x[i], &w[i]); if(w[i]==2) w[i]=-1; }
	int to=0;for(int i=1; i<=n; i++) {to=x[i]+t*w[i]; if(to>0) (mi+=to/m)%=n; if(to<0) (mi+=(to+1)/m-1)%=n; ans[i]=(to%m+m)%m;}
	sort(ans+1, ans+n+1), mi=(mi+n)%n;
	for(int i=mi+1; i<=n; i++) printf("%d\n", ans[i]); for(int i=1; i<=mi; i++) printf("%d\n", ans[i]);
	return 0;
}