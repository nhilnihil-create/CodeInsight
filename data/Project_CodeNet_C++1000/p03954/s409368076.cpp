#include<cstdio>
const int N=2e5+3,INF=1e9;
int n,a[N],b[N],f[N];
inline bool Check(int g){
	int tmp=0,l=n+n,r=0;
	for(int i=1;i<n+n;i++)b[i]=a[i]>g;
	for(int i=2;i<n+n;i++)tmp+=b[i]^b[i-1];
	if(tmp==n+n-2)return!b[1];
	if(b[n]==b[n+1]||b[n]==b[n-1])return!b[n];
	for(int i=n;i>1;i--)
	  if(b[i]==b[i-1]){l=i;break;}
	for(int i=n;i+1<n+n;i++)
	  if(b[i]==b[i+1]){r=i;break;}
	if(l==n+n)return!b[r];
	if(!r)return!b[l];
	return!b[n-l>r-n?r:l];
}
int main(){
	int l,r,m;
	scanf("%d",&n);
	for(int i=1;i<n+n;i++)scanf("%d",a+i);
	for(l=-INF,r=INF;l<r;)m=l+r>>1,Check(m)?r=m:l=m+1;
	printf("%d",l);
	return 0;
}