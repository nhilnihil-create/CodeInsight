#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t,a,b,i,j,k,n;
    cin>>n>>k>>a>>b;
    i=0;
    cout<<min(k,n)*a+max(i,(n-k))*b<<endl;
    return 0;
}
