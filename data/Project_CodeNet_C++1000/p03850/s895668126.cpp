#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
template<class T> inline void cmax(T &x,T y) { if(y>x) x=y; }
int sign(int x) { return x&1?-1:1; }
const int N=1e5+10;
ll f[N][3];
int A[N],n;
char op[N][2];
int main() {
	rd(n); rd(A[1]),op[1][0]='+';
	for(int i=2;i<=n;++i) {
		scanf("%s",op[i]);
		rd(A[i]);
	}
	memset(f,-0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<3;++j) {
			//f[i-1][j]
			if(op[i][0]=='-') {
				if(j<2) cmax(f[i][j+1],f[i-1][j]+sign(j+1)*A[i]);
				cmax(f[i][j],f[i-1][j]+sign(j+1)*A[i]);
				if(j>0) cmax(f[i][j-1],f[i-1][j]+sign(j+1)*A[i]);
			}
			else {
				cmax(f[i][j],f[i-1][j]+sign(j)*A[i]);
				if(j>0) cmax(f[i][j-1],f[i-1][j]+sign(j)*A[i]);
			}
		}
	ll ans=-1e18;
	for(int j=0;j<3;++j) cmax(ans,f[n][j]);
	printf("%lld",ans);
	return 0;
}