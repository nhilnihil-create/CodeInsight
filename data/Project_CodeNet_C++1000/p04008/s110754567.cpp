# include <bits/stdc++.h>
# define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
ll read(){
	ll x=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
const int maxn = 1e5+10;
int n,k;
int a[maxn];
int cnt[maxn];
int dep[maxn];
int q[maxn];
int ans = 0;
int main(){
	n=read(),k=read();
	rep(i,1,n)a[i]=read(),cnt[a[i]]++;
	if(a[1]!=1){--cnt[a[1]];a[1]=1;ans++;}
	int l=0,r=0; 
	rep(i,1,n) if(!cnt[i])q[r++]=i;
	while (l<r){
		int h=q[l++]; if (h==1)break;
		if (a[h]!=1&&dep[h]==k-1)++ans;
		else dep[a[h]]=max(dep[a[h]],dep[h]+1);
		--cnt[a[h]]; if (!cnt[a[h]])q[r++]=a[h];
	}
	printf("%d\n",ans);
	return 0;
}