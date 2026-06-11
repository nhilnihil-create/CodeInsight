#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef string str;
const long long INF = INT64_MAX;

#define REP(i, n) for(ll i=0;i<n;i++)
#define WHOLE(v) (v).begin(), (v).end()
#define ASC(v) sort((v).begin(), (v).end())
#define DESC(v) sort((v).rbegin(), (v).rend())
#define INV(v) reverse((v).rbegin(), (v).rend())
#define FOLDL(src, dst, lambda) partial_sum((src).begin(), (src).end(), (dst).begin(), lambda)
#define ACCUM(v, d0, lambda) accumulate((v).begin(), (v).end(), d0, lambda)
#define FOLDR(src, dst, lambda) INV(src);partial_sum((src).begin(), (src).end(), (dst).begin(), lambda);INV(dst)
#define DESC(v) sort((v).rbegin(), (v).rend())
#define ERASE(v, i) v.erase(v.begin() + i)
#define UNIQ(v) ASC(v);erase(unique(v.begin(), v.end()), v.end())
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve() {
    ll H, W, N;
    cin >> H >> W >> N;
    set<pll> S;
    set<pll> B;
    for(int i = 0; i < N; i++) {
        ll a, b;
        cin >> b >> a;
        S.insert({a-1, b-1});
        for(int j = -1; j <= 1; j++) {
            for(int k = -1; k <= 1; k++) {
                ll x,y;
                x = a-1+j;y=b-1+k;
                if(x >= 1 && x < W - 1 && y >= 1 && y < H - 1){
                    B.insert({x, y});
                }
            }
        }
    }
    vll ans(10, 0);
    ans[0] = (H - 2) * (W - 2);
    for(auto &b:B) {
        ll ctr = 0;
        for(int j = -1; j <= 1; j++) {
            for(int k = -1; k <= 1; k++) {
                ctr += S.count({b.first+j, b.second+k});
            }
        }
        ans[ctr]++;
        ans[0]--;
    }
    for_each(WHOLE(ans), [&](auto r){cout << r << endl;});
}

int main() {
    FIO;
    solve();
    return 0;
}
