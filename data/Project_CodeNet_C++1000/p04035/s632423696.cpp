#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define loop(i,s,e) for(ll i=s;i<e;i++)
#define test ll x;cin>>x;while(x--)
#define pb push_back
#define vec vector<ll>
#define sortvec(x) sort(x.begin(),x.end())
#define sz(x) x.size()

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll sum=0;
    loop(i,0,n)
    {
    	cin>>a[i];
    	sum+=a[i];
    }

    ll red=0,pos;
    loop(i,0,n-1)
    {
    	if (a[i]+a[i+1]>=k)
    	{
    		pos=i+1;
    		red=1;
    		break;
    	}
    }
    if (red==0)
    	cout<<"Impossible\n";
    else
    {
    	cout<<"Possible\n";
    	loop(i,1,pos)
   			cout<<i<<"\n";

    	for(ll i=n-1;i>pos;i--)
    		cout<<i<<"\n";
    	
    	cout<<pos<<"\n";
    }

}
