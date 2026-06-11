#include<bits/stdc++.h>
using namespace std;
long long q,h,s,d,n,ans,x;
int main()
{
    cin>>q>>h>>s>>d>>n;
    x=min(q*4,min(h*2,s));
    if(x*2<=d)
        cout<<x*n;
    else
        cout<<((n%2)*x)+n/2*d;

    return 0;
} 