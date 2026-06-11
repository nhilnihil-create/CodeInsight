#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MN 5005
using namespace std;
typedef long long ll;
ll f[MN][MN];
int n,m;char ch[MN];
const int mod=1e9+7;
int pow(int x,int y){
	ll tmp=1;
	while(y){
		if(y&1)tmp=tmp*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}return tmp;
}
void add(ll &x,ll y){(x+=y)>=mod?x-=mod:0;}
int main(){
	scanf("%d%s",&n,ch+1);m=strlen(ch+1);f[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++){
			add(f[i+1][j+1],f[i][j]*2%mod);
			add(f[i+1][max(j-1,0)],f[i][j]);
		}printf("%lld\n",f[n][m]*pow(pow(2,m),mod-2)%mod);
}
