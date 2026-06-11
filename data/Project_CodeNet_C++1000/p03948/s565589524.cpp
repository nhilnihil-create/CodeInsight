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


struct Edge {
    int to, cost, nm;
    Edge(int to, int cost, int nm): to(to), cost(cost), nm(nm) {}
};

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<Edge>> AdjList;
AdjList graph;
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
const int INF = 100000000;

ll GCD(ll a, ll b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return GCD(b, a%b);
}

bool cmp(const pii& a, const pii& b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}



int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);

    ll N, T; cin >> N >> T;
    ll A[100010];
    for(int i=0; i<N; ++i) cin >> A[i];

    set<ll> st;
    for(int i=0; i<N; ++i) st.insert(A[i]);



    ll minV = INT_MAX;
    ll max_cost = 0;
    ll maxV = 0;
    for(int i=0; i<N; ++i){
        if(A[i] <= minV){
            minV = A[i];
        }
        maxV = max(maxV, A[i]);
        max_cost = max(max_cost, A[i]-minV);
    }

    vector<vector<int>> v(100010);

    int idx=0;
    map<ll, int> mp;

    for(auto e: st){
        mp[e] = idx;
        idx++;
    }


    for(int i=0; i<N; ++i){
        v[mp[A[i]]].push_back(i);
    }


    ll ans = 0;
    bool checked[100010]={false};
    for(int i=0; i<N; ++i){
        ll t1 = A[i];
        ll t2 = A[i] + max_cost;
        if(t2 > maxV) continue;
        
        
        if(st.find(t2)!=st.end() && v[mp[t2]][0] > i) ans++;
    }
    cout << ans << endl;

    return 0;
}