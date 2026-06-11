#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,a[maxn],mn=(1e9),mx;
ll s1,k,s2;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(a[i]),s1+=a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	s2=(ll)n*(n+1)/2;
	if (s1%s2!=0) { printf("NO\n"); return 0; }
	k=s1/s2;
	if (mn<k||mx>k*n) { printf("NO\n"); return 0; }
	for (int i=1;i<=n;i++)
		a[i]=(a[i]-k*i%n+n)%n;
	for (int i=1;i<=n;i++)
		if (a[i]!=a[1]) { printf("NO\n"); return 0; }
	printf("YES\n");
	return 0;
}