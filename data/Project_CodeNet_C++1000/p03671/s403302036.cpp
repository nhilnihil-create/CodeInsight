#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,m,n,p,q,r;
    cin>>a>>b>>c;

    m=a+b;
    n=b+c;
    p=a+c;
    q=min(m,n);
    r=min(p,q);

    cout<<r<<endl;

    return 0;
}
