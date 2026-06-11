#include<iostream>
#include<cstdio>
#include<set>
#define mk make_pair
using namespace std;
long long  n;
set<pair<int,int> > s;
int main()
{
	scanf("%lld",&n);
	int ma;
	for(ma=1;(1LL<<ma)<n;ma++);ma--;
	for(int i=1;i<=ma;i++)
	s.insert(mk(i,i));
	for(int i=1;i<=ma;i++)
	s.insert(mk(i+ma,i));
	s.insert(mk(ma+ma+1,ma+1));
	s.insert(mk(ma+ma+2,ma+1));
	int sz=ma+ma+2,nm=ma+1;
	for(int i=ma-1;~i;i--)
	if(n&(1LL<<i))
	{
		nm++;
		s.insert(mk(i,nm));
		s.insert(mk(sz,nm));
	}
	printf("%d\n",s.size());
	for(set<pair<int,int> >::iterator it=s.begin();it!=s.end();it++)
	printf("%d ",(*it).second);
	return 0;
}
	