#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
	ll a, b, c;
    cin>>a>>b>>c;
    ll o = c % b;
    for (ll i = a; i < 100000; i += a)
    {
        if(i%b == o)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}