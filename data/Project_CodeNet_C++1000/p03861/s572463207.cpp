#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double llf;
int main()
{
    ll a,b,x,aa,bb;
    cin>>a>>b>>x;
    aa=a/x;
    if(a%x!=0)
    {
        aa++;
    }
    bb=b/x;
    if(aa>bb)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<bb-aa+1<<endl;
    }
    
    return 0;
}