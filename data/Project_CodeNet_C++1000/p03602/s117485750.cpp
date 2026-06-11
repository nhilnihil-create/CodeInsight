#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <climits>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;


//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()



typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
const int INF = 100000000;

struct Edge {
    int to, from;
    ll cost;
    Edge(int from, int to, ll cost): from(from), to(to), cost(cost) {}
};

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};
typedef vector<vector<Edge>> AdjList;
AdjList graph;
bool cmpx(const pii& a, const pii& b){
    return a.first < b.first;
}
bool cmpy(const pii& a, const pii& b){
    return a.second < b.second;
}

bool comp(const Edge& e1, const Edge& e2) {
    return e1.cost < e2.cost;
}

ll A[310][310];
bool d_n[310][310];
int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);

    int N; cin >> N;

    REP(i, N) REP(j, N) {
            cin >> A[i][j];
        }
   REP(k, N){
        REP(i, N){
            REP(j, N){
                if(A[i][j] > A[i][k] + A[k][j]){
                    cout << -1 << endl;
                    return 0;
                }

                if(A[i][j]==A[i][k]+A[k][j] && A[i][k] > 0 && A[k][j] > 0){
                    d_n[i][j] = true;
                }
            }
        }
    }

    ll ans = 0;
    REP(i, N){
        REP(j, i+1){
            if(d_n[i][j] == false){
                ans += A[i][j];
            }
        }
    }
    cout << ans << endl;


    bool c = false;

    return 0;
}