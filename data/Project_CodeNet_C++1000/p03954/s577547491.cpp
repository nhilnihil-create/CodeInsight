#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N],b[N],g,m,n,l = 1e9+7,r,mid;
int main() {
	scanf("%d",&n);
	for(int i=1; i<=2*n-1; i++) {
		scanf("%d",&a[i]);
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	while (l <= r) {
		mid = l + r >> 1;
		int f = 1e8 + 7,q = 1e8 + 7, cnt = 0;
		for(int i=1; i<=2*n-1; i++)
			if(a[i]>=mid)b[i]=1,cnt++;
		for(int i=n+1,j=n-1; i<=n*2-1&&j>=1; i++,j--) {
			if(b[j]==0&&b[j+1]==0)f=min(f,n-j);
			if(b[i]==0&&b[i-1]==0)f=min(f,i-n);
			if(b[j]==1&&b[j+1]==1)q=min(q,n-j);
			if(b[i]==1&&b[i-1]==1)q=min(q,i-n);	
		}
		if(q<f)l=mid+1;
		else if(q>f) r=mid-1;
		else {
			if(cnt>=n)l=mid+1;
			else r=mid-1;
		}
		memset(b, 0, sizeof b);
	}
	printf("%d",r);
}