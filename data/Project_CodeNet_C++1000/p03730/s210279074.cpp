#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,a,b,c,sum=0;
    cin>>a>>b>>c;
    if(c%__gcd(a,b)==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}



