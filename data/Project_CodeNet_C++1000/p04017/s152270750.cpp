#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 100002
using namespace std;
int n,i,j,a[N],l,q,f[N][22];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	cin>>l>>q;
	for(i=1;i<=n;i++){
		int pos=lower_bound(a+1,a+n+1,a[i]+l)-a;
		if(a[pos]==a[i]+l) f[i][0]=pos;
		else f[i][0]=pos-1;
	}
	for(j=0;(1<<j)<=n;j++){
		for(i=1;i<=n;i++){
			if(f[i][j]==n) f[i][j+1]=0;
			else f[i][j+1]=f[f[i][j]][j];
		}
	}
	for(i=1;i<=q;i++){
		int x,y,ans=1<<30,tmp=0;
		cin>>x>>y;
		if(x>y) swap(x,y);
		for(j=log2(1.0*n);j>=0;j--){
			if(f[x][j]==0) continue;
			tmp+=pow(2,j);
			if(f[x][j]>=y){
				ans=min(ans,tmp);
				tmp-=pow(2,j);
			}
			else x=f[x][j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
