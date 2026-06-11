#include<bits/stdc++.h>
using namespace std;
int a[27];
int main()
{
    long long int i,j,k,z,t,x,y,n;
    cin>>n>>k>>x>>y;
    j=max(0LL,n-k);
    t=min(n,k);
    z=t*x+j*y;
    cout<<z<<endl;
}
