#include<bits/stdc++.h>
using namespace std;
int n;
int l;
int q;
int a[100001];
int s;
int b;
int f[100001][33];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    cin>>l>>q;
    for(int i=1;i<=n;++i){
    	int x=upper_bound(a+1,a+n+1,a[i]+l)-a-1;
    	if(a[i]+l>=a[n]) f[i][0]=n;
    	else f[i][0]=x;
    }
    for(int j=1;j<=30;j++)
        for(int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
    while(q--){
		scanf("%d %d",&s,&b);
		int i=1;
		int ans=0;
		if(s>b) s^=b^=s^=b;
		for(int i=30;i>=0;--i)
			if(f[s][i]<b)
				ans+=(1<<i),
				s=f[s][i];
			printf("%d\n",ans+1);
	}
	return 0;
}