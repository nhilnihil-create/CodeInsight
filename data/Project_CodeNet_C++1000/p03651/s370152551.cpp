#include<bits/stdc++.h>
#define lld long long int
#define pb push_back
#define in insert
#define mod 1000000007
#define pi 3.14159265358979

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lld n,k,x,f=0;
    cin>>n>>k;

    cin>>x;
    if(x>k)f=1;
    if(x==k){cout<<"POSSIBLE"<<"\n";return 0;}
    lld g=x;
    for(lld i=0;i<n-1;i++)
    {
        cin>>x;
        if(x>k)f=1;
        if(x==k){cout<<"POSSIBLE"<<"\n";return 0;}
        g=__gcd(g,x);
    }
    if(k%g==0&&g!=1&&f==1)
    {
        cout<<"POSSIBLE"<<"\n";
        return 0;
    }
    if(g==1&&f==1)cout<<"POSSIBLE"<<"\n";
    else cout<<"IMPOSSIBLE"<<"\n";
}
