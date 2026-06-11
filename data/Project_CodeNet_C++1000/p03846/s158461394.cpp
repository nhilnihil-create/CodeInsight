#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
    memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		arr[temp]++;
	}
	long long int count=1;
	int flag=0;
	for(int i=0;i<n;i++)
	 {
	 	if((arr[i]==1 && i!=0) || arr[i]>2)
	 	 {
	 	 	flag=1;
	 	 	break;
		 }
      if(i==0 && arr[i]==2)
      {
        flag=1;
        break;
      }
		 if(arr[i]==2)
		  count=(count*2)%1000000007;
	 }
	 if(flag!=1)
	  cout<<count<<endl;
	 else
	  cout<<0<<endl;
}