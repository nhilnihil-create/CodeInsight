#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pre[100010],pre1[100010],num[100010],n,ans;
bool bo[100010];
char s[233];

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();num[1]=rd();bo[1]=true;
	for (int i=2;i<=n;i++)
	{
		scanf("%s",s+1);num[i]=rd();
		bo[i]=(s[1]=='+');
	}
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+(bo[i]?num[i]:-num[i]);
	for (int i=1;i<=n;i++) pre1[i]=pre1[i-1]+num[i];
	ans=pre[n];
	int lst=0;
	for (int i=1;i<=n;i++)
	{
		if (bo[i]) continue;
		if (!lst) { lst=i;continue; }
		ans=max(ans,pre[lst-1]-(pre1[i-1]-pre1[lst-1])+(pre1[n]-pre1[i-1]));
		lst=i;
	}
	printf("%lld\n",ans);
	return 0;
}