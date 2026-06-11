#include <iostream>

using namespace std;
typedef long long ll;
const int N=1e5+7;

int vis[N];

bool solve(ll x, ll y)
{
    if(x<2&&y<2) return 0;
    for(ll i=1; 2*i<=x; i++)
        if(!solve(x-2*i,y+i)) return 1;
    for(ll i=1; 2*i<=y; i++)
        if(!solve(x+i,y-2*i)) return 1;
    return 0;
}

int main()
{
#ifdef local
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    if(abs(n-m)<2) cout<<"Brown";
    else cout<<"Alice";
    return 0;
}
