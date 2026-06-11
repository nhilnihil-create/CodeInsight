#include <bits/stdc++.h>
using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test=1;
	
	while(test--)
	{
	    long long B,a,b,c=0,k,d=0,i,n,j,temp,ans=1;
	    cin>>n;
	    long long arr[n+1]={0};
	    for(i=0;i<n;i++)
	    {
	        cin>>a;
	        arr[a]++;
	    }
	    if(n%2==0)
	    {
	        for(i=1;i<n;i+=2)
	        {
	            if(arr[i]==2)
	            {
	                ans*=2;
	                ans=ans%(1000000007);
	            }
	            else 
	            {
	                ans=0;
	                break;
	            }
	        }
	    }
	    else
	    {
	        for(i=0;i<n;i+=2)
	        {
	            if(arr[i]==2)
	            {
	                ans*=2;
	                ans=ans%(1000000007);
	            }
	            else if(i!=0 && arr[i]!=2)
	            {
	                ans=0;
	                break;
	            }
	        }
	    }
	    cout<<ans;
    }
}
