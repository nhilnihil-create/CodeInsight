#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n,ans=0;
    cin>>n;
    n*=2;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++)
	{
	    if(i%2!=0)
	    ans+=a[i];
	}
	cout<<ans;
	return 0; 
} 
