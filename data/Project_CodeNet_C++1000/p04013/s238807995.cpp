
#include<bits/stdc++.h>
using namespace std;
     
#define int long long
#define ll long long
#define f(i,l,n) for(int i=l;i<n;i++)
#define E "\n"
#define Outerloop int q;cin>>q;while(q--)
#define Mod 1000000007
int dp[55][55][2505];
int n,k,a[500],A;

int solve(int number,int id,int sum)
{
 
	
	
	if(id==0)
	{
		if(number!=0 && sum%number==0 )
		{if(sum/number==A) return 1;
		return 0;}
		else return 0;
	}
		if(dp[number][id][sum]!=-1) return dp[number][id][sum];
	    int temp=0;
		temp+=solve(number+1,id-1,sum+a[id]);
		temp+=solve(number,id-1,sum);
	
	return dp[number][id][sum]=temp;
}

    int32_t main()
    {
    	memset(dp,-1,sizeof dp);
    	
    	
    	cin >> n >> A;
    	
    	f(i,1,n+1) cin >> a[i];
    	
		

	    	cout<<solve(0,n,0)<<E;

    	
    return 0;
    }
    
    
    