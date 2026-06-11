#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll x=__gcd(a,b);
    if(c%x==0)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

}
