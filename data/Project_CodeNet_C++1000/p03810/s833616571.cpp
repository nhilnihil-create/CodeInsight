#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=200010;
int n,a[maxn]; ll ans;
int gcd(int x,int y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
bool ck() {
	int flag=0; ans=0;
	for (int i=1;i<=n;i++) ans+=a[i];
	if ((ans-n)%2==1) return 1;
	for (int i=1;i<=n;i++)
		if ((a[i]&1)&&a[i]>1) {
			if (flag) return 0;
			flag=1; a[i]--;
		}
	if (!flag) return 0;
	int g=a[1];
	for (int i=2;i<=n;i++) g=gcd(g,a[i]);
	for (int i=1;i<=n;i++) a[i]/=g;
	return ck()^1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	if (ck()) printf("First\n");
	else printf("Second\n");
	return 0;
}