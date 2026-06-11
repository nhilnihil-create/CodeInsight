#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n;
int a[2*maxn];
int b[2*maxn];
bool check(int x){
	memset(b,0,sizeof(b));
	for(int i=1;i<=2*n-1;i++)
		if(a[i]>x)b[i]=1;
	int tmp1=1,tmp2=2*n-1;
	for(int i=n-1;i>=1;i--)
		if(b[i]==b[i+1]){tmp1=i+1;break;}
	for(int i=n+1;i<=2*n-1;i++)
		if(b[i]==b[i-1]){tmp2=i-1;break;}
	if(n-tmp1<tmp2-n)return b[tmp1];
	return b[tmp2];
}
void search(){
	int l=0,r=2*n;
	while(l+1<r){
		int mid=l+((r-l)>>1);
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%d",r);
}
int main(){
    //freopen("pyramid.in","r",stdin);
    //freopen("pyramid.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	search();
    return 0;
}