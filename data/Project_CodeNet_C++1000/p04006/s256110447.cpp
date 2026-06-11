#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int res=0;
    char c;
    bool zf=0;
    while(((c=getchar())<'0'||c>'9')&&c!= '-');
    if(c=='-')zf=1;
    else res=c-'0';
    while((c=getchar())>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0';
    if(zf)return -res;
    return res;
}
int d[2005],a[2005][2005];
signed main(){
	int n=read(),m=read(),ans=2e16;
	for(register int i=1;i<=n;i++){
		d[i]=read();
	}
	for(register int i=1;i<=n;i++){
		a[i][i]=d[i];
		for(register int j=i+1;j<=n;j++){
			a[i][j]=min(a[i][j-1],d[j]);
		}
	}
	for(register int i=0;i<n;i++){
		int tmp=m*i;
		for(register int j=1;j<=n;j++){
			int k=j-i;
			if(k<=0)tmp+=min(a[1][j],a[k+n][n]);
			else tmp+=a[k][j];
		}
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}