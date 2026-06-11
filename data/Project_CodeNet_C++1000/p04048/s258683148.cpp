#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cal(ll a,ll b)
{
    if(a>b)swap(a,b);
    if(b%a==0)return a*(b/a)*2-a;
    return cal(b%a,a)+a*(b/a)*2;
}
int main()
{
    ll n,x;cin>>n>>x;
    cout<<cal(x,n-x)+n<<endl;
}
