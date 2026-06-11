#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    ll n,i,j,k,l,a,b,c,d,m,f1,f2;
    cin>>a>>b>>c;
    k=10000000000;
    l=k-b;
    l+=c;
    m=k+a;
    if(l<=k)
    {
        cout<<"delicious"<<endl;
    }
    else if(l>k&&l<=m)
    {
        cout<<"safe"<<endl;
    }
    else if(l>m)
    {
        cout<<"dangerous"<<endl;
    }
    return 0;
}
