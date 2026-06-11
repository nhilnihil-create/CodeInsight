#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, k, n) for(auto i = k; i != n; i++)
#define rrep(i, n) RREP(i, n, 0)
#define RREP(i, n, k) for(auto i = n; i != k; i--)
#define all(x, r) (x), (x)+(r)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " " << x << endl
#define exst(x, data) (data).find(x) != (data).end()
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define np next_permutation
#define b32 bitset<32>

using ll = long long;
using Pii = pair<int,int>;
using Tiii = tuple<int, int, int>;
template<class T>using V = vector<T>;

const int dx[9] = {-1, -1, -1, 0, 0, 1, 1, 1, 0};
const int dy[9] = {-1, 0, 1, -1, 1, -1, 0, 1, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll H, W, N; cin >> H >> W >> N;

    map<Pii, int> m;
    V<ll> ans = V<ll>(10, 0); ans[0] = (H-2) * (W-2);
    REP(i,1,N+1) {
        int a, b; cin >> a >> b;
        rep(j,9) {
            int nx = b+dx[j], ny = a+dy[j];
            if(1<nx && nx<W && 1<ny && ny<H) {
                Pii n_xy = mp(nx,ny);
                if(m[n_xy] < 10) ans[m[n_xy]]--;
                m[n_xy]++;
                if(m[n_xy] < 10) ans[m[n_xy]]++;
            }
        }
    }

    rep(i,10) cout << ans[i] << endl;
    // REP(itr,m.begin(),m.end()) cout << itr->second << " "; cout << endl;
    return 0;
}
