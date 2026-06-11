#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,m,q,ans[10];
map<ll,bool> M;
ll haxi(int i,int j) {
	return (ll)(i-1)*m+j;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(q); int x,y,cnt;
	while (q--) {
		read(x); read(y);
		for (int i=max(1,x-2);i<=x;i++) {
			if (i+2>n) break;
			for (int j=max(1,y-2);j<=y;j++) { cnt=0;
				if (j+2>m) break;
				for (int k1=0;k1<=2;k1++)
				for (int k2=0;k2<=2;k2++)
					cnt+=M[haxi(i+k1,j+k2)];
				ans[cnt]--; ans[cnt+1]++;
			}
		} M[haxi(x,y)]=1;
	} cnt=0;
	for (int i=1;i<=9;i++) cnt+=ans[i];
	printf("%lld\n",(ll)(n-2)*(m-2)-cnt);
	for (int i=1;i<=9;i++) printf("%d\n",ans[i]);
	return 0;
}