#include <bits/stdc++.h>
using namespace std;																																																																																																																																							auto Nextint=[]()->int{int x;scanf("%d",&x);return x;};

int n,a[1000001];

bool check(int x)
{
	vector<int> pos;
	auto func=[x](int p)->bool{return a[p]>=x;};auto proc=[](bool a,bool b,bool c)->bool{return a==b||b==c;};
	for(int i=2;i<=2*(n-1);++i)if(proc(func(i-1),func(i),func(i+1)))pos.push_back(i);
	if(pos.empty())return func(1);
	auto res=0,maxn=INT_MAX;
	for(auto i : pos)if(abs(i-n)<maxn)res=i,maxn=abs(i-n);
	return func(res);
}

int main()
{
	n=Nextint();
	for(int i=1;i<=2*n-1;++i)[](int i)->void{a[i]=Nextint();}(i);
	auto l=1,r=2*n,ans=0;
	while(l<=r)
	{
		auto mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;else r=mid-1;
	}
	printf("%d\n",ans);
}