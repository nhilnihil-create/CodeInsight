#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll h[100005];
bool ok(ll k,ll &n,ll &a,ll &b)
{
	ll temp=b*k;
	for(int i=0;i<n;i++)
	{
		if(h[i]>temp)k-=ceil((double)(h[i]-temp)/((a-b)*1.0));
		if(k<0)return false;
	}
	return true;
}

int main()
{
   std::ios_base::sync_with_stdio(false);
   ll n,a,b;
   cin>>n>>a>>b;
   for(int i=0;i<n;i++)cin>>h[i] ;
   sort(h,h+n,greater<int>());
   int lo=1,hi=1e9+1;
   while(lo<hi)
   {
   	int mid=lo+(hi-lo)/2 ;
   	bool temp=ok(mid,n,a,b);
   	//cout<<mid<<" "<<temp<<" ";
   	if(temp)hi=mid;
   	else lo=mid+1 ;
   }
   cout<<lo ;
}