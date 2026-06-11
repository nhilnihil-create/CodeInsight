#include<bits/stdc++.h>
#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=1e5+7;

int a[N],n;

inline int read()
{
	int o=0; char ch=' ';
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())o=o*10+ch-48;
	return o;
}

inline int gcd(int x,int y)
{return y==0?x:gcd(y,x%y);} 

int solve()
{
	int odd=0,even=0,k;
	fo(i,1,n)(a[i]&1)?++odd:++even;
	if(even&1)return 1;
	if(odd>1)return 0;
	fo(i,1,n)if(a[i]&1){k=i;break;}
	if(a[k]==1)return 0;
	--a[k];
	int g=a[1];
	fo(i,2,n){
		g=gcd(g,a[i]);
		if(g==1)break;
	}
	fo(i,1,n)a[i]=a[i]/g;
	return (1^solve());
}

int main()
{
	n=read();
	fo(i,1,n)a[i]=read();
	if(solve()==1)puts("First");else puts("Second");
}