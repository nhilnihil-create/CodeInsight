#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}
long long N,A,B,tmp;
long long h[100010];
bool check(long long mid)
{
	tmp=0;
	for(int i=1;i<=N;++i)
	{
		if(h[i]<=B*mid)
			continue;
		tmp+=(h[i]-B*mid)/A;
		if((h[i]-B*mid)%A!=0)
			++tmp;
		if(tmp>mid)
			return 0;
	}
	return 1;
}
int main()
{
	long long L,R,mid;
	scanf("%d%lld%lld",&N,&A,&B);
	A-=B;
	for(int i=1;i<=N;++i)
	{
		scanf("%lld",&h[i]);
	}
	L=1;R=1000000000;
	while(L<R)
	{
		//cout<<L<<" "<<R<<endl;
		mid=(L+R)/2;
		if(check(mid))
			R=mid;
		else
			L=mid+1;
		//cout<<L<<" "<<R<<endl;
	}
	cout<<L<<endl;
}