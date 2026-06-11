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
    if(v[0]+v[1]==v[2])
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    return 0;
}
