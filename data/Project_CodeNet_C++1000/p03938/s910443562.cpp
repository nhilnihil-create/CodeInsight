#include<bits/stdc++.h>
using namespace std;

const int N=20005;
int n,p[N],a[N],c[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",p+i),c[p[i]]=i+(int)9e8;
	a[1]=1;
	for(int i=2;i<=n;++i)a[i]=a[i-1]+max(1,-(c[i-1]-c[i])+1);
	for(int i=1;i<=n;++i)printf("%d%c",a[i]," \n"[i==n]);
	for(int i=1;i<=n;++i)printf("%d%c",c[i]-a[i]," \n"[i==n]);
}
