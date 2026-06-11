#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll x;
    cin>>x;
    ll s[x*3];

    for(ll i=0;i<3*x;i++)
    {
        cin>>s[i];
    }

    sort(s,s+3*x);

    ll c=0;

    for(int i=x;i<3*x;i=i+2)
    {
        c+=s[i];
    }
     cout<<c;


}