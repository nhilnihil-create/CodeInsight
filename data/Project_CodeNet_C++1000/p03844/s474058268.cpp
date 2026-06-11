//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a[2];
char c;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll j=0;
	for(ll i=1; i<=3; i++)
	{
	    if(i&1)
	    {
	        cin>>a[j];
	        ++j;
	    }
	    else
	    cin>>c;
	}
	if(c=='-')
	cout<<a[0]-a[1];
	else
	cout<<a[0]+a[1];
	return 0;
}
