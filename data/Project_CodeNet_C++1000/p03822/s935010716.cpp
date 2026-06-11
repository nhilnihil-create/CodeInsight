//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <chrono>
#include <complex>
#include <regex>
#include <locale>
#include <random>
#include <cassert>
#include <type_traits>

using namespace std;

// typedef
//------------------------------------------
typedef long long LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VLL> VVLL;
typedef vector<VVI> VVVI;
typedef vector<VVLL> VVVLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<VPII> VVPII;
typedef vector<VPLL> VVPLL;
typedef vector<VS> VVS;
typedef map<int, int> MII;
typedef map<LL, LL> MLL;
typedef map<string, int> MSI;
typedef map<int, string> MIS;

// container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i, arr) for(typeof((arr).begin()) i=(arr).begin(); i!=(arr).end(); ++i)
#define EXIST(str, e) ((str).find(e)!=(str).end())
#define COUNT(arr, v) count((arr).begin(), (arr).end(), v)
#define SEARCH(v, w) search((v).begin(), (v).end(), (w).begin(), (w).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define REVERSE(c) reverse((c).begin(), (c).end())
#define ROTATE_LEFT(arr, c) rotate((arr).begin(), (arr).begin()+(c), (arr).end())
#define ROTATE_RIGHT(arr, c) rotate((arr).rbegin(), (arr).rbegin() + (c), (arr).rend())
#define SUMI(arr) accumulate((arr).begin(), (arr).end(), 0)
#define SUMD(arr) accumulate((arr).begin(), (arr).end(), 0.)
#define SUMLL(arr) accumulate((arr).begin(), (arr).end(), 0LL)
#define MULD(arr) accumulate((arr).begin(), (arr).end(), 1., multiplies<double>())
#define UB(arr, n) upper_bound((arr).begin(), (arr).end(), n)
#define LB(arr, n) lower_bound((arr).begin(), (arr).end(), n)
#define PB push_back
#define MP make_pair
#define ft first
#define sd second


// input output
//------------------------------------------
#define GL(s) getline(cin, (s))
#define INIT() std::ios::sync_with_stdio(false);std::cin.tie(0)
#define OUT(d) std::cout<<(d)
#define OUT_L(d) std::cout<<(d)<<endl
#define FOUT(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)
#define FOUT_L(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)<<"\n"
#define EL() printf("\n")
#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v) {std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yay() printf("Yay!\n")
#define Nnn() printf(":(\n")
#define CE(x, y) ((x + y - 1) / (y))


template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)
        in >> x;
    return in;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]" << "\n";
    return out;
}

template<class T1, class T2>
inline bool chmin(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T1, class T2>
inline bool chmax(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


//repetition
//------------------------------------------
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n)  FOR(i,0,n)
#define RREP(i, n) for(int i = n-1;i >= 0;i--)
#define FORLL(i, a, b) for(LL i=LL(a);i<LL(b);++i)
#define RFORLL(i, a, b) for(LL i=LL(b)-1;i>=LL(a);--i)
#define REPLL(i, n) for(LL i=0;i<LL(n);++i)
#define RREPLL(i, n) for(LL i=LL(n)-1;i>=0;--i)
#define FOREACH(x, arr) for(auto &(x) : (arr))

//------------------------------------------
//------------------------------------------

template<class T>
struct Edge {
    int from, to;
    T cost;

    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const { return to; }
};

template<class T>
using Edges = vector<Edge<T>>;

template<class T>
using WeightedGraph = vector<Edges<T>>;

using UnWeightedGraph = vector<vector<int>>;

template<class T>
using DistMatrix = vector<vector<T>>;

struct GraphAdapter {
    template<class T>
    static UnWeightedGraph to_unweighted_graph(const WeightedGraph<T> &origin) {
        int V = origin.size();
        UnWeightedGraph graph(V);
        for (int i = 0; i < V; i++) for (auto &e: origin[i]) graph[i].push_back((int) e);
        return graph;
    }

    static WeightedGraph<int> to_weighted_graph(const UnWeightedGraph &origin) {
        int V = origin.size();
        WeightedGraph<int> graph(V);
        for (int i = 0; i < V; i++) for (auto to: origin[i]) graph[i].push_back({i, to, 1});
        return graph;
    }

    template<class T>
    static DistMatrix<T> to_dist_matrix(const WeightedGraph<T> &origin, T INF) {
        int V = origin.size();
        DistMatrix<T> matrix(V, vector<T>(V, INF));
        for (int i = 0; i < V; i++) for (auto &e:origin[i]) matrix[i][e.to] = e.cost;
        for (int i = 0; i < V; i++) matrix[i][i] = 0;
        return matrix;
    }
};

int dfs(int v, UnWeightedGraph &G) {
    if (G[v].size() == 0) return 0;
    vector<int> dp;
    for (auto to:G[v]) dp.push_back(dfs(to, G));
    RSORT(dp);
    for (int i = 0; i < dp.size(); i++) dp[i] += (i + 1);
    return *max_element(dp.begin(), dp.end());
}


int main() {

    int N;
    cin >> N;

    UnWeightedGraph G(N);
    for (int i = 0; i < N - 1; i++) {
        int x;
        cin >> x;
        x--;
        G[x].push_back(i + 1);
    }


    cout << dfs(0, G) << endl;
}




























