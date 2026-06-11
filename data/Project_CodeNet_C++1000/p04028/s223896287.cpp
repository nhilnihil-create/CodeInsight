#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define lb(x) ((x)&(-(x)))
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define dalao 1000000007
#define inf 0x3f3f3f3f
#define N 5010
using namespace std;
typedef long long ll;
int n,m,f[2][N<<1];
char s[N];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%dalao)if(b&1)r=1ll*r*a%dalao;return r;}
inline void upd(int& a,int b){a=a+b>=dalao?a+b-dalao:a+b;}
int main(){
	scanf("%d%s",&n,s+1),m=strlen(s+1);
	f[0][0]=1;
	for(int i=1,z=1;i<=n;i++,z^=1){
		for(int j=0;j<=n+m;j++){
			f[z][j]=f[z^1][j+1];
			if(j)upd(f[z][j],(f[z^1][j-1]<<1)%dalao);
			else upd(f[z][j],f[z^1][j]);
		}
	}
	printf("%lld",1ll*f[n&1][m]*pw(pw(2,m),dalao-2)%dalao);
	return 0;
}