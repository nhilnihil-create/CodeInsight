#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int t,q; cin>>t ;for(q=1;q<=t;q++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    ll i,n,a=0;
    cin>>n;
    for(i=1;;i++)
    {
        a+=i;
        if(a>=n)break;
    }
    cout<<i;
}
