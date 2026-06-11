#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const int MOD = 1000000007;
#define MAX_N 200010

class UnionFind {
    public:
        // size: Union-Find で扱いたい要素の数
        UnionFind(int size) { m_Data.assign(size, -1); }

        // x と y の属する集合を併合
        // 既に一緒な集合内にいるなら false を
        // 新たに併合されたなら true を返す
        bool Unite(int x, int y) {
            x = Find(x), y = Find(y);
            if(x == y) { return (false); }
            if(m_Data[x] > m_Data[y]) { swap(x, y); }
            m_Data[x] += m_Data[y];
            m_Data[y] = x;
            return (true);
        }

        // 要素 k が属する集合の根を返す
        int Find(int k) {
            if(m_Data[k] < 0) { return (k); }
            return (m_Data[k] = Find(m_Data[k]));
        }

        // 要素 k と同じ集合の要素数を返す
        int Size(int k) { return (-m_Data[Find(k)]); }

    private:
        vector<int> m_Data;
};

int N, K, L;
vector<int> graphK[MAX_N];
vector<int> graphL[MAX_N];
UnionFind* pUfK;
UnionFind* pUfL;
UnionFind* pUfAll;

vector<int> group[MAX_N];   // グループ i に所属するノード

void dfs_k(int cur) {
    for(auto& to : graphK[cur]) {
        if(pUfK->Find(cur) == pUfK->Find(to)) { continue; }
        pUfK->Unite(cur, to);
        dfs_k(to);
    }
}
void dfs_l(int cur) {
    for(auto& to : graphL[cur]) {
        if(pUfL->Find(cur) == pUfL->Find(to)) { continue; }
        pUfL->Unite(cur, to);
        dfs_l(to);
    }
}

signed main()
{
    cin >> N >> K >> L;

    REP(i, K) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        graphK[p].push_back(q);
        graphK[q].push_back(p);
    }
    REP(i, L) {
        int r, s;
        cin >> r >> s;
        r--; s--;
        graphL[r].push_back(s);
        graphL[s].push_back(r);
    }
    UnionFind ufk(N);
    UnionFind ufl(N);
    UnionFind ufall(N);
    pUfK = &ufk;
    pUfL = &ufl;
    pUfAll = &ufall;
    REP(i, N) { if(ufk.Size(i) == 1) { dfs_k(i); } }
    REP(i, N) { if(ufl.Size(i) == 1) { dfs_l(i); } }
    REP(i, N) { group[ufl.Find(i)].push_back(i); }
    REP(i, N) {
        if(ufall.Size(i) == 1 && ufk.Size(i) > 1 && ufl.Size(i) > 1) {
            for(auto& n : group[ufl.Find(i)]) {
                if(ufk.Find(i) == ufk.Find(n)) { ufall.Unite(i, n); }
            }
        }
    }
    REP(i, N) {
        printf("%lld", ufall.Size(i));
        if(i == N-1) { printf("\n"); }
        else { printf(" "); }
    }
    return 0;
}
