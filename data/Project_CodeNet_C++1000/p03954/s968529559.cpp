#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    return x*f;
}
const int N=2e5+28;
int n,a[N],b[N];
signed main(){
    //freopen("night.in","r",stdin);
    //freopen("night.out","w",stdout);
    n=read()*2-1;
    for(int i=1;i<=n;i++)a[i]=read();
    int l=0,r=0x7fffffff,ans=0x7fffffff;
    while(l<=r){
	int mid=(l+r)>>1;
	for(int i=1;i<=n;i++)
	    b[i]=(a[i]>mid);
	int p1=n/2,p2=n/2+2;
	int re=-1;
	for(;p1;p1--,p2++){
	    if(b[p1]==b[p1+1]){
		re=b[p1];
		break;
	    }
	    if(b[p2]==b[p2-1]){
		re=b[p2];
		break;
	    }
	}
	if(re==-1)re=b[1];
	if(re==0)ans=mid,r=mid-1;
	else l=mid+1;
    }
    printf("%lld",ans);
    return 0;
}
/*
7
1 2 3 4 3 2 1
5
1 9 2 3 6
*/
