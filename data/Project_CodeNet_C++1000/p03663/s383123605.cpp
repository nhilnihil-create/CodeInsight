//QWsin
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

string ans;

inline int query(ll x){
	cout<<"? "<<x<<endl;
	cin>>ans;return ans=="Y";	
}

inline int solve1()
{
	ll fac=1;
	for(int i=1;i<=10;++i,fac*=10)
		if(!query(fac)) return i-1;
	return -1;
}

inline void spj()
{
	int fac=9;
	
	for(int i=1;i<=10;++i,fac=fac*10+9)
		if(query(fac)) {cout<<"! "<<(long long)pow(10,i-1)<<endl;return ;}
}

int main()
{
	int len=solve1();
	if(len==-1) return spj(),0;
	
	ll num=0;
	for(int i=len;i>1;--i)
	{
		int l= (i==len)?1:0,r=9,ans=-1;
		
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(query(num+mid*pow(10,i-2))) l=mid+1,ans=mid;
			else r=mid-1;
		}
		
		num+=ans*pow(10,i-2);
	}
	
	num*=100;
	int l=len==1?1:0,r=9,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(query(num+mid*10)) r=mid-1,ans=mid;
		else l=mid+1;	
	}
	num+=ans*10;
	cout<<"! "<<num/10<<endl;
	return 0;
}
