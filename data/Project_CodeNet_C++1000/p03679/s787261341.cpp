#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,p,q,x,c1,c2,c3,d,e,f;
    ll n,m,z;
    vector<ll>v;
    cin>>n>>m>>z;
    if(z<=m) cout<<"delicious"<<endl;
    else if(z>n+m) cout<<"dangerous"<<endl;
    else if(z>m && z<=(n+m)) cout<<"safe"<<endl;
}
