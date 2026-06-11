#include <bits/stdc++.h>
using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test=1;
	
	while(test--)
	{
	    long long a,b,c=1,k,i,n,j,ans,temp,p,m;
	   
	    int arr[4];
	    for(i=0;i<3;i++)
	    cin>>arr[i];
	   // cout<<arr[0]<<arr[1]<<arr[2];
	    sort(arr,arr+3);
	    if((arr[0]+arr[1])==arr[2])
	    cout<<"Yes";
	    else cout<<"No";
	   // cout<<arr[0]<<arr[1]<<arr[2];
	    
    }
    
}
