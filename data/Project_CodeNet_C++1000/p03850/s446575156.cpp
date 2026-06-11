#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100100;
int i,j,k,n,ch;
int a[N],op[N];
ll f[N][3];
void R(int &x) {
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
void W(ll x) {
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
int main() {
	R(n);
	for (i=1;i<n;i++) {
		R(a[i]);
		ch=getchar();
		while (ch!='+' && ch!='-') ch=getchar();
		if (ch=='-') op[i]=1;
		else op[i]=0;
	}
	R(a[n]);
	memset(f,190,sizeof f);
	f[1][0]=a[1];
	for (i=1;i<n;i++) {
		for (j=0;j<=2;j++) {
			if (op[i]) {
				if ((j&1)^1) f[i+1][j]=max(f[i+1][j],f[i][j]-a[i+1]);
				else f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1]);
				if (j<2) {
					if ((j&1)^1) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]-a[i+1]);
					else f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+a[i+1]);
				}
			}
			else {
				if (j&1) f[i+1][j]=max(f[i+1][j],f[i][j]-a[i+1]);
				else f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1]);	
			}
		}
		f[i+1][1]=max(f[i+1][1],f[i+1][2]);
		f[i+1][0]=max(f[i+1][0],f[i+1][1]);
	}
	W(f[n][0]);puts("");
}