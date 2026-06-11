//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int ans[500][500];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int H,W,w,h;
    cin>>H>>W>>h>>w;
    if (H%h==0&&W%w==0)
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";
    for (int i=0;i<H;i++)
    {
        for (int j=0;j<W;j++)
            ans[i][j]=-1000;
    }
    for (int i = 0; i < H; i += h) {
        for (int j = 0; j < W; j += w)
            ans[i][j] = 1000*(h * w-1)-1;
    }
//    } else
//    {
//        for (int i = 0; i < W; i += w) {
//            for (int j = 0; j < H; j += h)
//                ans[j][i] = h * w - 2;
//        }
//    }
    rep(i,H) {
        rep(j, W) {
            cout << ans[i][j] << " ";
        }
        cout<<'\n';
    }
}
