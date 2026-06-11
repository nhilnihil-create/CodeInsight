#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>l>>n>>m;
    if(m>n)
    {
        r=max(0,(m-n-l));
    }
    else
    {
        r=max(0,(n-m-l));
    }
    cout<<r<<"\n";
    return 0;
}

