#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool inc = true;
    int ans =0;
    if( a[0] > a[1])
        inc = false;
    bool br = false;
    for(int i=0;i<n-1;i++)
    {
        if( a[i]== a[i+1])
            continue;
        if( br )
        {
            if( a[i] > a[i+1])
                inc = false;
            else inc = true;
            br = false;
        }
        if( a[i] > a[i+1] && inc == true )
        {
            ans ++;
            br = true;
        }
        if( a[i] < a[i+1] && inc == false)
        {
            ans++;
            br = true;
        }
    }
    cout<<ans+1;
}