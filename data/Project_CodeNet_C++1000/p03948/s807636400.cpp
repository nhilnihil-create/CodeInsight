#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5+10;

ll a[MAXN];
int main()
{
    int n,t;
    cin>>n>>t;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll differ = 0ll;
    ll cnt = 0ll;
    ll most =1e18+8;
    for(int i = 1; i<= n;i++)
    {
        if( differ < a[i]-most)
        {
            differ = a[i]-most;
            cnt = 1;
        }
        else if(differ == a[i]-most)
        {
            cnt++;
        }
        most = min(most,a[i]);
    }
    cout<<cnt<<endl;
}
