#include<bits/stdc++.h>

using namespace std;

const int N=505,M=250005;
int n,m,l,r,x[N],a[M],id[N],num[N];
inline bool comp(const int&a,const int&b){return x[a]<x[b];}
inline void Assert(bool f){if(!f)puts("No"),exit(0);}

int main(){
	scanf("%d",&n),m=n*n;
	for(int i=1;i<=n;i++)scanf("%d",&x[i]),a[x[i]]=i,id[i]=i;
	for(l=1;a[l];l++);for(r=m;a[r];r--);sort(id+1,id+n+1,comp);
	for(int i=1;i<=n;i++){
		int k=id[i];
		for(int j=1;j<k;j++){
			Assert(l<x[k]);
			for(a[l]=k;a[l];l++);
		}
	}
	for(int i=n;i>=1;i--){
		int k=id[i];
		for(int j=k+1;j<=n;j++){
			Assert(r>x[k]);
			for(a[r]=k;a[r];r--);
		}
	}
	puts("Yes");
	for(int i=1;i<=m;i++)printf("%d%c",a[i]," \n"[i==m]);
	return 0;
}