#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100100;
int i,j,k,n,l,t,ff,ch,st;
int x[N],w[N];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
int main() {
	R(n);R(l);R(t);
	st=0;
	for (i=0;i<n;i++) {
		R(x[i]);R(w[i]);
		if (w[i]==1) st=(st+t/l)%n;
		else st=(st+n-t/l)%n;
		int tt=t%l;
		if (w[i]==1) {
			x[i]+=tt;
			if (x[i]>=l) x[i]-=l,st=(st+1)%n;
		}
		else {
			x[i]-=tt;
			if (x[i]<0) x[i]+=l,st=(st+n-1)%n;
		}
	}
	sort(x,x+n);
	for (i=st;i<st+n;i++) printf("%d\n",x[i%n]);
}