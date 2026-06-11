#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi pair<ll,int> 
#define pii pair<int,ll>
 
ll mod = 1e9+7;
ll INF = 1e17;
/*ll gcd(ll a,ll b)
{
    if(a==0)
    return(b);
    return(gcd(b%a,a));
}*/
int main()
{
    IOS
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<((a+b)*c)/2<<endl;
    return(0);
}
