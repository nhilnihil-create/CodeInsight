#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main() {
    long test=1;
    // cin>>test;
    while(test--)
    {
	long t,i,j,n,a,b,c,d,ans,A,B;
	string s,s1,s2,s3;
	cin>>n>>t;
	long arr[n];
	ans=n*t;
	c=0;
	for(i=0;i<n;i++)cin>>arr[i];
	for(i=1;i<n;i++)
	{
	    c+=arr[i-1]+t-arr[i]>0?arr[i-1]+t-arr[i]:0;
	}
	cout<<ans-c;
    }
	return 0;
}