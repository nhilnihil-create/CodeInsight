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
// 隣接リスト
vector<int> graphK[MAX_N];
vector<int> graphL[MAX_N];
// 道路と鉄道で連結されているもの
UnionFind* pUfK;
UnionFind* pUfL;
UnionFind* pUfAll;
// グループ i に所属するノード
vector<int> groupK[MAX_N];
vector<int> groupL[MAX_N];

// 道路を深さ優先
void dfs_k(int cur) {
    for(auto& to : graphK[cur]) {
        if(pUfK->Find(cur) == pUfK->Find(to)) { continue; }
        pUfK->Unite(cur, to);
        dfs_k(to);
    }
}
// 鉄道を深さ優先
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

    // グラフ作成
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
    // 道路と鉄道で連結しているものをグループ化
    UnionFind ufk(N);
    UnionFind ufl(N);
    UnionFind ufall(N);
    pUfK = &ufk;
    pUfL = &ufl;
    pUfAll = &ufall;
    REP(i, N) { if(ufk.Size(i) == 1) { dfs_k(i); } }
    REP(i, N) { if(ufl.Size(i) == 1) { dfs_l(i); } }
    REP(i, N) {
        groupK[ufk.Find(i)].push_back(i);
        groupL[ufl.Find(i)].push_back(i);
    }

    // 両方で連結しているものを愚直に探す
    REP(i, N) {
        if(ufall.Size(i) == 1 && ufk.Size(i) > 1 && ufl.Size(i) > 1) {
            // なんかうまいこと高速化
            if(ufk.Size(i) < ufl.Size(i)) {
                for(auto& n : groupK[ufk.Find(i)]) {
                    if(ufl.Find(i) == ufl.Find(n)) { ufall.Unite(i, n); }
                }
            } else {
                for(auto& n : groupL[ufl.Find(i)]) {
                    if(ufk.Find(i) == ufk.Find(n)) { ufall.Unite(i, n); }
                }
            }
        }
    }
    // 答え表示
    REP(i, N) {
        printf("%lld", ufall.Size(i));
        if(i == N-1) { printf("\n"); }
        else { printf(" "); }
    }
    return 0;
}
