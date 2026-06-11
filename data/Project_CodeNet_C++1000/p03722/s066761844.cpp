#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}

struct edge {int f, t, c;};
const int MINF = -1e18;

V(edge) E;
vi dis(1050, MINF);
int N, M;
V(bool) T(1050, false);
bool updated;

void update(int &x, int y) {
    if(x < y) {
        x = y;
        updated = true;
    }
}

void bellmanford() {
    dis[0] = 0;
    rep(i, N) {
        rep(j, M) {
            updated = false;
            update(dis[E[j].t], dis[E[j].f]+E[j].c);
            if(updated) T[E[j].t] = true;
            else T[E[j].t] = false;
        }
    }
}

signed main(){
    cin >> N >> M;
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        E.pb(edge{a, b, c});
    }

    int res = 0;
    bellmanford();
    if(T[N-1]) cout << "inf" << endl;
    else cout << dis[N-1] << endl;
    
    return 0;
}