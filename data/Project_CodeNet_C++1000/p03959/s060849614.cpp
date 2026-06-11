#include<iostream>
using namespace std;
#include<vector>
#define int long long int
#define mod  1000000007
int32_t main()
{
	 
      int n;
      cin>>n;
      int arr1[n],arr2[n];
      int j;
      for(j=0;j<n;j++)
      {
		  cin>>arr1[j];
	  }
	  for(j=0;j<n;j++)
	     cin>>arr2[j];
	  vector<int> v1(n,-1),v2(n,-1);
	  int maxval=0;
	  for(j=0;j<n;j++)
	  {
		  if(arr1[j]>maxval)
		  {
			  maxval=arr1[j];
			  v1[j]=maxval;
		  }
	  }
	  maxval=0;
	  for(j=n-1;j>=0;j--)
	  {
		  if(arr2[j]>maxval)
		  {
			  maxval=arr2[j];
			  v2[j]=maxval;
		  }
	  }
      bool result=true;
      for(j=0;j<n;j++)
      {
		  if(v1[j]!=-1&&v2[j]!=-1&&v1[j]!=v2[j])
		  {
			  result=false;
			  break;
		  }
		  if(v1[j]!=-1&&v1[j]>arr2[j])
		  {
			  result=false;
			  break;
		  }
		  if(v2[j]!=-1&&v2[j]>arr1[j])
		  {
			  result=false;
			  break;
		  }
	  }
	  if(!result)
	  {
		  cout<<0<<endl;
	  }
	  else
	  {
		  int answer=1;
		  vector<int> v(n,-1);
		  for(j=0;j<n;j++)
		  {
			  if(v1[j]!=-1)
			  {
				  v[j]=v1[j];
			  }
			  else if(v2[j]!=-1)
				 v[j]=v2[j];
		  }
		  int ptr=1;
		  while(ptr<n)
		  {
			  if(v[ptr]==-1)
              {
				  			   int value=min(arr1[ptr],arr2[ptr]);
			   answer=answer*value;
			   answer=answer%mod;
			  }
			   ptr++;
		  }
		  cout<<answer<<endl;
	  }
}
