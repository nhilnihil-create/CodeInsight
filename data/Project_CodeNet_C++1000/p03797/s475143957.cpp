#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int M = 1e9+7;

using namespace std;

main()
{
    fast;
    ll n,m;
    cin>>n>>m;
    if (n==m/2)
        cout<<n<<endl;
    else if (n<m/2)
    {
        m-=2*n;
        cout<<n+m/4<<endl;
    }
    else
        cout<<min(n,m/2)<<endl;
}