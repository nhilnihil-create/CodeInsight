#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int h[100005];
inline bool check(long long times)
{
	long long tmp=times;
    for(int i=1;i<=n;i++)
    {
        long long blood=h[i]-b*times;
        if(blood>0)
        {
            long long cnt=blood/(a-b)+(blood%(a-b)==0?0:1);
            tmp-=cnt;
            if(tmp<0)
            {
            	return false;
			}
        }
    }
    return true;
}
int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	int lb=0,rb=1e9,mid;
	int ans=0;
	while(lb<=rb)
	{
		mid=(lb+rb)/2;
		if(check(mid))
		{
			ans=mid;
			rb=mid-1;
		}
		else
		{
			lb=mid+1;
		}
	}
	cout<<ans;
	return 0;
}