#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;
typedef long long ll;
const ll inf=1LL<<61;
const int N=100100;
int n;ll a[N],f[3][N];
char s[N];ll op[N];
 
ll cg(int x){return (x&1)?-1:1;}
int main(){
	scanf("%d",&n);op[1]=1;
	for (int i=1;i<n;i++){
		scanf("%d%s",a+i,s);
		if (s[0]=='-')
			op[i+1]=-1; else op[i+1]=1;
	}
	scanf("%d",&a[n]);
	f[0][1]=a[1];f[1][1]=f[2][1]=-inf;
	for (int i=2;i<=n;i++){
		for (int j=0;j<=2;j++) f[j][i]=-inf;
		for (int j=0;j<=2;j++)
			for (int k=0;k<=j;k++)
				f[k][i]=max(f[k][i],f[j][i-1]+op[i]*a[i]*cg(k));
		if (op[i]==-1){
			for (int j=2;j;j--)
				f[j][i]=max(f[j][i],f[j-1][i]);
		}
	}
	printf("%lld\n",max(max(f[0][n],f[1][n]),f[2][n]));
}