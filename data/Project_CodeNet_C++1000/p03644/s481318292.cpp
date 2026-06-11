#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    ll n; cin>>n;
    ll ans=1;
    while(1)
    {
        if(ans==n)
        {
            cout<<ans;
            break;
        }
        else if(ans>n)
        {
            cout<<ans/2;
            break;
        }
        ans=ans*2;
    }
}


