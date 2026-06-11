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
    	ll n,s=0,m=0,l,mx=0,x,i,t=0,j=0,k=0;
    	cin>>n>>l;
    	ll a[n],b[n];
    	f(i,n)
    	cin>>a[i];
    	f(i,n-1)
    	{
    	    b[i]=a[i]+a[i+1];
    	    if(b[i]>=l)
            {
                j=i;
                t=1;
            }
    	}
    	if(t==0)
            cout<<"Impossible\n";
        else{
            cout<<"Possible\n";
            f1(i,j)
            cout<<i<<endl;
            for(i=n-1;i>j;i--)
                cout<<i<<endl;
        }
}





