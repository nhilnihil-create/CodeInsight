#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t,a,b,i,j,k,n,x;
    cin>>a>>b>>x;
    k=(b/x)-(a/x);
    if(a%x==0)
        k+=1;
    cout<<k<<endl;
    return 0;
}
