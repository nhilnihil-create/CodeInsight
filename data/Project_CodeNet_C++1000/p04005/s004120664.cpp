#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ll a[3];
    for(int i=0;i<3;i++)
        cin>>a[i];
    sort( a, a+3);
    if( a[2]%2==0)
        cout<<0;
    else cout<<a[0]*a[1];
}