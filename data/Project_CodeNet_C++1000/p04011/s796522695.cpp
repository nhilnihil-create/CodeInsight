#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    if(n>=k)
    {
    ll a=k*x;
    ll b=y*(n-k);
    ll c=a+b;
    cout<<c<<endl;
    }
    else
    {
        ll c=n*x;
        cout<<c<<endl;
    }

}
