#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,t,i,j,c,v[200005];
    cin>>n>>t;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    c=0;
    for(i=1;i<n;i++)
    {
        if(t>=v[i]-v[i-1])c+=(v[i]-v[i-1]);
        else c+=t;
    }
    cout<<c+t<<endl;
    return 0;
}
