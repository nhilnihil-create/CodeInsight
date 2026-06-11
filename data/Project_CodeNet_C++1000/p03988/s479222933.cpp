#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,w[N],cnt[N];
inline int read()
{
    int num=0; char g=getchar();
    while(g<48||57<g) g=getchar();
    while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar();
    return num;
}
int main()
{
	n=read(); int val=0,sum; for(int i=1;i<=n;i++) w[i]=read(),cnt[w[i]]++,val=max(val,w[i]);
	if(n!=2&&val==1) {puts("Impossible"); return 0;} sum=val+1;
	while(sum>0)
	{
		if(sum>=2) {if(cnt[val]<2) {puts("Impossible"); return 0;} cnt[val]-=2,sum-=2;}
		else {if(cnt[val]<=0) {puts("Impossible"); return 0;} sum--,cnt[val]--;} val--;
	}
	val++; for(int i=1;i<=n;i++) if(cnt[i]&&i<=val) {puts("Impossible"); return 0;} puts("Possible");
	return 0;
}