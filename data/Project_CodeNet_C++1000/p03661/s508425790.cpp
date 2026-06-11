#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	int kk=1,k=0;if (c=='-')kk=-1,c=getchar();
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}int n,a[1000000],ans;
signed main(){
	n=read();for (int i=1;i<=n;i++)a[i]=read()+a[i-1];
	ans=1e15;for (int i=1;i<n;i++)ans=min(ans,abs(a[n]-a[i]*2));
	cout<<ans<<endl;
}
