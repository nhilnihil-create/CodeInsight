#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
#define N 105
int n,m,a[N],cnt,len;
int main(){
	scanf("%d%d",&n,&m);
	rep (i,1,m) scanf("%d",&a[i]),cnt+=(a[i]&1);
	if (m==1){
		if (n==1) printf("1\n1\n1");else printf("%d\n2\n%d 1\n",n,n-1);
		return 0;
	}
	if (cnt>2) return puts("Impossible"),0;
	rep (i,1,m)
		if (a[i]&1)
			if (!(a[1]&1)) swap(a[1],a[i]);else swap(a[m],a[i]);
	rep (i,1,m) printf("%d ",a[i]);puts("");
	len=m;if (a[m]==1) len--;
	printf("%d\n",len);
	rep (i,1,m){
		if (i==1) printf("%d ",a[1]+1);
		else if (i==m){if (a[m]>1) printf("%d ",a[m]-1);}
		else printf("%d ",a[i]);
	}
	return 0;
}
