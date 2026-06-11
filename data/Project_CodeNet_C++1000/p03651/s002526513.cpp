#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    long long n,x,i,j,k,y,z,g,mx;
    g=0;
    cin>>n>>x;
    mx=0;
    for (i=0;i<n;i++)
    {
    	cin>>arr[i];
    	mx=max(mx,arr[i]);
    	g=__gcd(g,arr[i]);
	}
	if (mx<x || (x%g)!=0)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		cout<<"POSSIBLE"<<endl;
	}
}