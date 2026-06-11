#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//int numberofPaths(int h,int w,int a,int b);

int main()
{
    ll n,i,len1,h,t,cnt=0,cnt1=0,x,m,flag=0,k,h1=0,h2=0,od=0,ev=0,y,l;
    double w;
   /* freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin>>n>>l;
	ll a[n];
	for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        if(a[i]+a[i-1]>=l)
        {
            len1=i;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"Impossible"<<endl;
    }
    else{
            cout<<"Possible"<<endl;
   // cout<<len1<<endl;
        for(i=1;i<len1;i++)
        {
            cout<<i<<endl;
        }
        for(i=n-1;i>len1;i--)
        {
            cout<<i<<endl;
        }
        cout<<len1<<endl;
    }
	return 0;
}
