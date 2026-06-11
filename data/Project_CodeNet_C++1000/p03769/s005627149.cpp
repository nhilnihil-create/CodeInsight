#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

typedef long long ll;
const int N=210;
std::vector<int> V;
ll n;

int main()
{
	scanf("%lld",&n),n++;
	int tot=0,flag=0;
	for(ll k=1ll<<50;k;k>>=1)
	{
		if(tot){if(flag)V.push_back(++tot);else flag=1;}
		if(n&k)V.insert(V.begin(),++tot);
	}
	printf("%d\n",tot*2);
	for(auto it:V)printf("%d ",it);
	for(int i=1;i<=tot;i++)printf("%d ",i);
	printf("\n");
	return 0;
}
