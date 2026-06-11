#include <bits/stdc++.h>
#define maxn 200005
int arr[maxn],n,seq[maxn],rank[maxn],ref[maxn];

int cmp(int a,int b){return arr[a]<arr[b];}

int check(int x){
//	printf("checking:%d\n",x);
	int mid=(n/2)+1;
	for (int i=1;i<=n;++i) {
		seq[i]=(ref[i]>x);
		//printf("%d ",seq[i]);
	}//printf("\n");
	if (seq[mid]==seq[mid-1]||seq[mid]==seq[mid+1]) return seq[mid];
	for (int i=1;i<n/2;++i)
		if (seq[mid-i]==seq[mid-i-1]||seq[mid+i]==seq[mid+i+1]) return seq[mid-i];
	return seq[1];
}

int main(){
//	freopen("triangle.in","r",stdin);
//	freopen("triangle.out","w",stdout);
	scanf("%d",&n);n=n*2-1;
	for (int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
		rank[i]=i;
	}if (n==1) {printf("%d ",arr[1]);return 0;}
	std::sort(rank+1,rank+n+1,cmp);
	for (int i=1;i<=n;++i) ref[rank[i]]=i;
//	for (int i=1;i<=n;++i) printf("%d ",ref[i]); printf("\n");
	int l=1,r=n,ans=1;
	while (l<r){
		int mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else {r=mid;ans=mid;}
	}printf("%d",arr[rank[ans]]);
	return 0;
}

