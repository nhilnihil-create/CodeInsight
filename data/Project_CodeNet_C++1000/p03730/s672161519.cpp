#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    cin>>a>>b>>c;
    if(c%__gcd(a,b)==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}