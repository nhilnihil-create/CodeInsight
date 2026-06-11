#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,a[N],b[N];
inline bool check(int x){
	for (int i=1;i<2*n;i++) b[i]=(a[i]>=x);
	if (b[n]==b[n+1]||b[n-1]==b[n]) return b[n];
	for (int i=n,j=n;i>=1&&j<2*n;i--,j++){
		if (b[i]==b[i+1]) return b[i];
		if (b[j]==b[j-1]) return b[j];
	}
	return b[n]^(n&1)^1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<2*n;i++) scanf("%d",&a[i]);
	int l=1;int r=2*n;
	while (l+1<r){
		int mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	if (check(r)) printf("%d\n",r);else printf("%d\n",l);
	return 0;
}