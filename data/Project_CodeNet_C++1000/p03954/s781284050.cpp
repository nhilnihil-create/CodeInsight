#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
int b[N];
int check(int k){
	for (int i=1;i<n*2;i++)
		b[i]=a[i]>k;
//	for (int i=1;i<n*2;i++)
//		printf("%d",b[i]);
	int m=n;
	int L=m,R=m;
	while (L>1&&b[L]!=b[L-1])
		L--;
	while (R<n*2-1&&b[R]!=b[R+1])
		R++;
	if (L==m||R==m)
		return b[m];
	if (b[L]==b[R])
		return b[L];
	return m-L>R-m?b[R]:b[L];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n*2;i++)
		scanf("%d",&a[i]);
	int L=1,R=n*2-1,mid,ans=R;
	while (L<=R){
		mid=(L+R)>>1;
		if (!check(mid))//printf(" ret = 0\n"),
			R=mid-1,ans=mid;
		else//	printf(" ret = 1\n"),
			L=mid+1;
	}
	printf("%d",ans);
	return 0;
}