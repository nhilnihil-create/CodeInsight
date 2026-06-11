#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,x=0;
    cin>>n;
    if ((n%11)&&(n%11<7))
        x=1;
    else if (6<n%11)
        x=2;
    cout<<(n/11)*2+x;
    return 0;
}