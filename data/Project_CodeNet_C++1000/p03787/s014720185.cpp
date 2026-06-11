//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 100005
#define oo 2000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll sqr(ll x) {return x*x;}

int n, m, color[maxN], cntSingle, cntBipartite, cntNormal, cntVtx;
bool isBipartite;

vector<int> g[maxN];

void DFS(int u, int c) {
    color[u] = c;
    ++cntVtx;
    for(int v: g[u]) {
        if (color[v] == 0) DFS(v, 3-c);
        else if (color[v] != 3-c) isBipartite = false;
    }
}

int main () {
    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    fto(u, 1, n) {
        if (color[u] == 0) {
            isBipartite = true;
            cntVtx = 0;
            DFS(u, 1);

            if (cntVtx == 1) ++cntSingle;
            else if (isBipartite) ++cntBipartite;
            else ++cntNormal;
        }
    }

    ll ans = sqr(cntBipartite+cntNormal)+sqr(cntBipartite);
    ans += sqr(n)-sqr(n-cntSingle);
    cout << ans;

    return 0;
}
