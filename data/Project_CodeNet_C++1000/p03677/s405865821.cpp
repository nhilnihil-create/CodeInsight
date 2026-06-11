#include<bits/stdc++.h>
#define P pair<long long,long long>//a+bx
#define MP(a,b) make_pair((long long)(a),(long long)(b))
using namespace std;
P Op[3001000];
int A[1001000];
int N,M;
int MM;
void Add(int i,int is,int it,int s,int t,P add)
{
	if(s==t||i>=2*MM)
		return ;
	if(is==s&&it==t)
	{
		Op[i].first+=add.first;
		Op[i].second+=add.second;
		return ;
	}
	int mid=(is+it)/2;
	if(t<mid)
		Add(i*2,is,mid,s,t,add);
	else if(s<mid)
	{
		Add(i*2,is,mid,s,mid,add);
		Add(i*2+1,mid,it,mid,t,add);
	}
	else	Add(i*2+1,mid,it,s,t,add);
	return ;
}
void Count(int s,int t)
{
	if(s<t)
	{
		Add(1,1,MM+1,1,s+1,MP(t-s,0));
		Add(1,1,MM+1,s+1,t+1,MP(t+1,-1));
		Add(1,1,MM+1,t+1,M+1,MP(t-s,0));
	}
	else
	{
		Add(1,1,MM+1,1,t+1,MP(t+1,-1));
		Add(1,1,MM+1,t+1,s+1,MP(M+t-s,0));
		Add(1,1,MM+1,s+1,M+1,MP(M+t+1,-1));
	}
}
int main()
{
	cin>>N>>M;
	int MMM=M;
	MM=1;
	while(MMM)
	{
		MMM/=2;
		MM*=2;
	}
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<N-1;i++)
		Count(A[i],A[i+1]);
	long long Min=1e18;
	for(int i=1;i<=M;i++)
	{
		int Pos=MM+i-1;
		long long Sum=0;
		while(Pos)
		{
			Sum+=Op[Pos].first+Op[Pos].second*i;
			Pos/=2;
		}
		Min=min(Min,Sum);
	}
	cout<<Min<<endl;
	return 0;
}