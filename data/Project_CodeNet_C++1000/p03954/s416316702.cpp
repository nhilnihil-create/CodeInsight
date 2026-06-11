#include <bits/stdc++.h>
using namespace std;
const int MAX_N=200005;
int A[MAX_N];
bool B[MAX_N];
int n;
int val(int pos)
{
	if(B[pos]!=B[pos+1])return n;
	return min(abs(pos-n),abs(pos+1-n));
}
bool check(int m)
{
//	cout<<"check:"<<m<<endl;
	memset(B,false,sizeof(B));
	for(int i=1;i<2*n;i++)if(A[i]>=m)B[i]=true;
	int pos=0,mi=n;
	for(int i=1;i<2*n-1;i++)
	{
		if(val(i)<mi)
		{
			mi=val(i);
			pos=i;
		}
	}
/*	for(int i=1;i<2*n;i++)cout<<B[i]<<" ";
	cout<<endl;*/
	if(pos==0)return n%2?B[n]:!B[n];
	else return B[pos];
}
int main()
{
	cin>>n;
	for(int i=1;i<2*n;i++)cin>>A[i];
	int lb=0,ub=2*n-1;
	while(ub-lb>1)
	{
		int mid=(lb+ub)/2;
		if(check(mid))lb=mid;
		else ub=mid;
	}
	cout<<lb<<endl;
	return 0;
}
