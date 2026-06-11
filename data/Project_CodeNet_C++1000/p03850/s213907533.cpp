#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define LL long long
using namespace std;

int n;
LL a[MAXN];
int b[MAXN];
LL f[MAXN][3];

inline void update(LL &x,LL y){ if(y>x) x=y; }

int main(){
	scanf("%d",&n);
	b[1]=1;
	scanf("%lld",a+1);
	for(int i=2;i<=n;i++){
		char c;
		while((c=getchar())==' ');
		b[i]=(c=='+'?1:-1);
		scanf("%lld",a+i);
	}
	memset(f,0x88,sizeof f);
	f[1][0]=a[1];
	for(int i=2;i<=n;i++)
		if(b[i]==1){
			update(f[i][0],f[i-1][0]+a[i]);
			update(f[i][0],f[i-1][1]+a[i]);
			update(f[i][0],f[i-1][2]+a[i]);
			update(f[i][1],f[i-1][1]-a[i]);
			update(f[i][1],f[i-1][2]-a[i]);
			update(f[i][2],f[i-1][2]+a[i]);
		}else{
			update(f[i][0],f[i-1][0]-a[i]);
			update(f[i][1],f[i-1][0]-a[i]);
			update(f[i][0],f[i-1][1]-a[i]);
			update(f[i][1],f[i-1][1]+a[i]);
			update(f[i][2],f[i-1][1]+a[i]);
			update(f[i][0],f[i-1][2]-a[i]);
			update(f[i][1],f[i-1][2]+a[i]);
			update(f[i][2],f[i-1][2]+a[i]);
		}
	printf("%lld\n",max(max(f[n][0],f[n][1]),f[n][2]));
	return 0;
}
