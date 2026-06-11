# include <bits/stdc++.h>
using namespace std;
# define int long long
# define ll long long
const int MAXN=2e6+1;

int read()
{
	int s=0,w=1;
	char ch;
	ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-'){
		   w=-1;
		}
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

ll n,a[MAXN],r[MAXN],l[MAXN],stac[MAXN],top,ans;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
	}
	for (int i=1;i<=n;i++){
		l[i]=0;
		r[i]=n+1;
	}
	for (int i=1;i<=n;i++){
		while (top && a[stac[top]]>a[i]){
			r[stac[top--]]=i;
		}
		l[i]=stac[top];
		stac[++top]=i;
	}
	for (int i=1;i<=n;i++){
		ans+=1ll*(r[i]-i)*(i-l[i])*a[i];
	}
	printf("%lld",ans);
	return 0;
}
