//Bismillahir-Rahmanir-Rahim
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int llu;
#define f1(i,n) for(i=1;i<=n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define Max 100009
#define Mx 1e10
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
    	ll n,mn=0,mx=0,x,i,t=0,j=0,k=0;
    	set<ll>s;
    	cin>>n;
    	ll a[n],c[n],g[n];
    	f(i,n)
    	{
    	    cin>>a[i];
    	}
        sort(a,a+n);
        for(i=n-1;i>=0;i--)
        {
            if(a[i]==a[i-1]&&a[i-1]==a[i-2]&&a[i-2]==a[i-3])
            {
                t=max(t,a[i]*a[i]);
            }
            else if(a[i]==a[i-1]&&mx==0)
            {
                mx=a[i];
            }
            else if(a[i]==a[i-1]&&mx!=a[i]&&a[i]>mn)
            {
                mn=a[i];
            }
            if(mx>0&&mn>0)
                k=max(k,mx*mn);
        }
         cout<<max(k,t)<<endl;
}




