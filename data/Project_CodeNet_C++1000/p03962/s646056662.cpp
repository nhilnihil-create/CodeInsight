#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t,a,b,i,j,k,n,x;
    vector<ll>v;
    for(i=0;i<3;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    ll c=1;
    if(v[0]!=v[1])
    {
        c++;
    }
    if(v[1]!=v[2])
    {
        c++;
    }
    cout<<c<<endl;
    return 0;
}
