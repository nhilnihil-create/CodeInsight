#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define rt return
using dbl = double;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

vi G[100001];

int f(int u, int p) {
    if (u != 0 && sz(G[u]) == 1) { // leaf
        return 0;
    }
    int sm = 0;
    each(v, G[u])if (v != p) {
        sm ^= f(v, u) + 1;
    }
    return sm;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; // 2<=N<=10^5
    cin >> N;

    rep(i, N - 1) {
        int x, y; // 1<=x,y<=N
        cin >> x >> y;
        --x; --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int gr = f(0, -1);
    cout << (gr ? "Alice" : "Bob") << endl;
}
