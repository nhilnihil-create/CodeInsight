#include<bits/stdc++.h>
using namespace std;
#define ll long long int



int main()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    ll m,p,x,s,temp;
    cin>>m;
    for(ll i=1;i<=m;i++)
    {   
    	s=0;
    	cin>>p>>x;
    	temp=a[p-1];
    	a[p-1]=x;
    	for(ll i=0;i<n;i++)
    	{
    		s=s+a[i];
    	}
    	cout<<s<<endl;
    	a[p-1]=temp;
    }
   
    return 0;
}