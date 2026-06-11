#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005
using namespace std;
typedef long long ll;
int a[N],op[N],n;
ll f[N][3];
int main(){
	scanf("%d",&n);
	const ll inf=1LL<<60;
	char aa[2];
	for(int i=1;i<=n;i++){
		if(i>1) scanf("%s",aa);
		else aa[0]='+';
		scanf("%d",&a[i]);
		op[i]=aa[0]=='+'?1:-1;
		for(int p=0;p<3;p++) f[i][p]=-inf;
	}
	f[0][2]=f[0][1]=-inf;
	for(int i=1;i<=n;i++){
		f[i][2]=f[i-1][2]+a[i];
		if(op[i]==1){
			f[i][0]=max(f[i-1][0],f[i-1][1])+a[i];
			f[i][1]=f[i-1][1]-a[i];
		}else{
			f[i][0]=-inf;
			f[i][1]=f[i-1][0]-a[i];
			f[i][2]=max(f[i][2],f[i-1][1]+a[i]);
		}
	}
	printf("%lld",max(f[n][0],max(f[n][1],f[n][2])));
	return 0;
}