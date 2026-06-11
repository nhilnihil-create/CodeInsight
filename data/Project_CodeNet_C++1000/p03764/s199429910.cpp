#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,i,j,x,y,ansx=0,ansy=0,a[100006],b[100006];
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(j=0;j<m;j++)
	{
		cin>>b[j];
	}
	sort(a,a+n);
	sort(b,b+m);
	for(i=0;i<n;i++)
	{
		x=i*a[i];
		y=(n-1-i)*a[i];
		x-=y;
		while(x<0)
		{
			x+=mod;
		}
		x%=mod;
		ansx+=x;
		ansx%=mod;
	}
	
	for(i=0;i<m;i++)
	{
		x=i*b[i];
		y=(m-1-i)*b[i];
		x-=y;
		while(x<0)
		{
			x+=mod;
		}
		x%=mod;
		ansy+=x;
		ansy%=mod;
        //cout<<ansy<<endl;
	}
    //cout<<ansx<<" "<<ansy<<" ";
	cout<<(ansx*ansy)%mod;
	return 0;
}	