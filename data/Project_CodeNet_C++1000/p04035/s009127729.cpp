#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1 << 30;


int main()
{
    int n; ll L;
    cin >> n >> L;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<int> res;
    rep(i,n-1) {
        if(a[i]+a[i+1] >= L) {
            res.push_back(i);
            break;
        }
    }

    if(res.empty()) {
        cout << "Impossible\n";
        return 0;
    }

    for(int i = res[0] + 1; i < n-1; ++i) res.push_back(i);
    for(int i = res[0] - 1; i >= 0; --i) res.push_back(i);
    cout << "Possible\n";
    drep(i,n-1) cout << res[i]+1 << "\n";
    return 0;
}