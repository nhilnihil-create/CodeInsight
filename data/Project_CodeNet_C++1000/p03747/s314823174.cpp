#include <bits/stdc++.h>
using namespace std;
struct point
{
	int ds;
	int ps;
}pnt[5000005];
int rk;
bool cmp(point a,point b)
{
	return a.ps<b.ps;
}
int main()
{
	int N,L,T;
	cin>>N>>L>>T;
	for(int i=0;i<N;i++)
	{
		cin>>pnt[i].ps>>pnt[i].ds;
	}
	for(int i=0;i<N;i++)
	{
		if(pnt[i].ds==1) pnt[i].ps+=T;
		else pnt[i].ps-=T;
		rk+=(pnt[i].ps/L);
		if(pnt[i].ps<0&&pnt[i].ps%L)
		{
			rk--;
		}
		pnt[i].ps%=L; 
		pnt[i].ps=(pnt[i].ps+L)%L;
		
	}
	rk%=N;
	rk=(rk+N)%N;
	sort(pnt,pnt+N,cmp);
	for(int i=rk;i<N;i++)
	{
		cout<<pnt[i].ps<<endl;
	}
	for(int i=0;i<rk;i++)
	{
		cout<<pnt[i].ps<<endl;
	}
	return 0;
}
