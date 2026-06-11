#include <stdio.h>
#include <string.h>
#define R register
#define MN 5005
#define P 1000000007
typedef long long ll;
char s[MN];int n,f[MN][MN],len;
inline void rw(int &x,int y){if ((x+=y)>=P) x-=P;}
inline int mul(int x,int y){return (ll)x*y%P;}
inline int pw(int x,int k){
	R int res=1;
	for (; k; k>>=1,x=mul(x,x)) 
		if (k&1) res=mul(res,x);
	return res;
}
int main(){
	scanf("%d%s",&n,s+1);
	len=strlen(s+1);f[0][0]=1;
	for (R int i=1; i<=n; ++i)
		for (R int j=0; j<=n; ++j){
			rw(f[i][j],f[i-1][j+1]);if (!j) rw(f[i][j],f[i-1][j]);
			if (j) rw(f[i][j],f[i-1][j-1]),rw(f[i][j],f[i-1][j-1]);
		}
	printf("%d\n",mul(f[n][len],pw(pw(2,len),P-2)));
}