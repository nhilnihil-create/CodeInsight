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
#define maxN 1000005
#define MOD 1000000007
#define oo 1000000000000000007LL
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

struct Graph {
private:
    vector<vector<int> > g;
    vector<int> comp;
    int n, id;
public:
    Graph(int n): n(n) {
        g.assign(n+1, vector<int>());
    }

    void addEdge(int u, int v) {
        g[u].pb(v); g[v].pb(u);
    }

    void DFS(int u) {
        comp[u] = id;
        for(int v: g[u]) {
            if (!comp[v]) DFS(v);
        }
    }

    vector<int> getComp() {
        comp.assign(n+1, 0);
        id = 0;
        fto(u, 1, n) {
            if (!comp[u]) {
                ++id;
                DFS(u);
            }
        }
        return comp;
    }
};

int main () {
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);

    Graph g1(n), g2(n);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        g1.addEdge(u, v);
    }
    fto(i, 1, l) {
        int u, v;
        scanf("%d%d", &u, &v);
        g2.addEdge(u, v);
    }

    vector<int> comp1 = g1.getComp(), comp2 = g2.getComp();

    map<ii, int> ma;
    fto(i, 1, n) ma[mp(comp1[i], comp2[i])]++;

    fto(i, 1, n) printf("%d ", ma[mp(comp1[i], comp2[i])]);

    return 0;
}
