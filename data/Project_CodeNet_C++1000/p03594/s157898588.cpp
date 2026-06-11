#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll a[505][505];
string s;
vector<pii> f;
bool good(ll x, ll y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int main() {
    //freopen("input.txt","r",stdin);
    string pat = "RGBY";
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            ll x = ((i+j)%(2*k) >= k?0:1);
            x += ((i-j+20000*k)%(2*k) >= k?0:2);
            //cout << x;
            printf("%c",pat[x]);
        }
        cout << endl;
    }
    return 0;
}
