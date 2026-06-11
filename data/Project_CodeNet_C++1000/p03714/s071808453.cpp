#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<cmath>
#define int long long int
int function(int arr[],int index,int n,int memo[])
{
	if(memo[index]!=-1)
	{
		return memo[index];
	}
	else
	{
		int j;
		bool result=false;
		int val=arr[index];
		for(j=index+val;j<=n;j+=val)
		{
			if(arr[j]>arr[index])
			{
				int here=function(arr,j,n,memo);
				if(here==0)
				{
					result=true;
					break;
				}
			}
		}
		for(j=index-val;j>=1;j-=val)
		{
			if(arr[j]>arr[index])
			{
				int here=function(arr,j,n,memo);
				if(here==0)
				{
					result=true;
				}
			}
		}
		if(result)
		{
			memo[index]=1;
			return 1;
		}
		else
		{
			memo[index]=0;
			return 0;
		}
	}
}
int32_t main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int n;
	 cin>>n;
	 int arr[3*n+1];
	 int j;
	 for(j=1;j<=3*n;j++)
	 {
		 cin>>arr[j];
	 }
	 int prefix[3*n+1]={0};
	 int sum=0;
	 multiset<int> st;
	 for(j=1;j<=n;j++)
	 {
		 sum+=arr[j];
		 st.insert(arr[j]);
	 }
	 prefix[n]=sum;
	 for(j=n+1;j<=2*n;j++)
	 {
		 int x=arr[j];
		 int y=*st.begin();
		 if(x>y)
		 {
			 st.erase(st.begin());
			 st.insert(x);
			 sum+=(x-y);
		 }
		 prefix[j]=sum;
	 }
	 int suffix[3*n+1];
	 multiset<int> st2;
	 int sum2=0;
	 for(j=3*n;j>2*n;j--)
	 {
		 sum2+=arr[j];
		 st2.insert(arr[j]);
	 }
	 suffix[2*n+1]=sum2;
	 for(j=2*n;j>n;j--)
	 {
		 int x=arr[j];
		 int y=*st2.rbegin();
		 if(x<y)
		 {
			 auto it=st2.end();
			 it--;
			 st2.erase(it);
			 st2.insert(x);
			 sum2+=(x-y);
		 }
		 suffix[j]=sum2;
	 }
	 int answer=-1000000000000000000;
	 for(j=n;j<=2*n;j++)
	 {
		 int here=prefix[j]-suffix[j+1];
		 answer=max(answer,here);
	 }
	 cout<<answer<<endl;
}
