#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

void solve()
{
	ll a,b,x;
	cin>>a>>b>>x;
    if(a%x==0)
        cout<<b/x-a/x+1;
    else 
    	cout<<b/x-a/x<<endl;
	return;
}

int main()
{
	fast;
	ll q=1;
	// cin>>q;
	while(q--)
		solve();
	return 0;
}

