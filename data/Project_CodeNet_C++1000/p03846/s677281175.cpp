#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

#define deb(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define END '\n'
#define inf 9e18
#define ff first
#define ss second
#define pb push_back

constexpr ll modu = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vi A(n), cnt(n, 0);
    cin >> A;
    for (int i = 0; i < n; ++i) ++cnt[A[i]];
    if (cnt[0] >= 2) {
        cout << "0\n";
        return;
    } else if (cnt[0] == 1) {
        bool ok = true;
        for (int i = 2; i < n; i += 2) {
            if (cnt[i] != 2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << binpow(2, n / 2, modu);
            return;
        } else cout << "0\n";
    } else {
        bool ok = true;
        for (int i = 1; i <= n; i += 2) {
            if (cnt[i] != 2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << binpow(2, n / 2, modu);
        } else cout << "0";
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}