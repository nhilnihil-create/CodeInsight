#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 400005
ll a[N],f[N][3];
int n,fl[N];
ll read(){
	#define gc getchar
	int x=0,f=0; char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc())
		if (ch=='-') f=1;
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return (f?-x:x);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		a[i]=read();
		fl[i]=(a[i]>0);
		a[i]=abs(a[i]);
	}
	memset(f,233,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=n;i++){
		if (!fl[i]) f[i-1][2]=f[i-1][1],f[i-1][1]=f[i-1][0],f[i-1][0]=-1e18;
		for (int cur=0;cur<=2;cur++)
			for (int now=0;now<=cur;now++)
				f[i][now]=max(f[i][now],f[i-1][cur]+(cur&1?-a[i]:a[i]));
	}
	printf("%lld\n",max(f[n][0],f[n][1]));
}