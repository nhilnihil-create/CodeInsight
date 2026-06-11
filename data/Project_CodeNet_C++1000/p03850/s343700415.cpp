#include <bits/stdc++.h>
using namespace std;
//#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll mod = 1e9 + 7;
const ll INF = 1<<30;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

ll n;
string a[200000 + 5];
ll sum[200000 + 5];

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    n += n - 1;
    rep(i, n) cin >> a[i];
    sum[0] = ll(stoi(a[0]));
    rep2(i, 1, n) {
        if(i % 2 == 0) continue;
        if (a[i] == "+") sum[i + 1] = sum[i - 1] + ll(stoi(a[i + 1]));
        else sum[i + 1] = sum[i - 1] - ll(stoi(a[i + 1]));
    }
    ll ans = ll(stoi(a[0]));
    rep2(i, 1, n) {
        if (i % 2 == 0) continue;
        if (a[i] == "+") ans += ll(stoi(a[i + 1]));
        else ans -= ll(stoi(a[i + 1]));
    }
    ll plus = 0;
    ll minus = 0;
    rrep2(i, n - 1, -1) {
        if (a[i] == "+") continue;
        if (a[i] == "-") {
            ans = max(ans, sum[i - 1] + plus + minus);
            plus += -minus;
            minus = 0LL;
        }
        else minus -= ll(stoi(a[i]));
    }
    cout << ans << endl;
}
