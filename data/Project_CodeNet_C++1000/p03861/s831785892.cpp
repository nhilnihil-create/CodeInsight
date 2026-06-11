#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll mod=1e9+7;
int main()
{
    ll a,b,x;
    cin>>a>>b>>x;
    ll p=b/x;
    p-=a/x;
    if(a%x==0)
    p++;
    cout<<p<<endl;
}