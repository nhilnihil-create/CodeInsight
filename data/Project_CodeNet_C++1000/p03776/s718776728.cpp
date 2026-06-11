#include <bits/stdc++.h>

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


struct Edge {
    int to, from;
    ll cost;
    Edge(int from, int to, ll cost): from(from), to(to), cost(cost) {}
};

typedef vector<vector<Edge>> AdjList;
AdjList graph;

vector<ll> v;
int main() {
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll com[51][51]={0};
    for(int i=0; i<51; ++i){
        com[i][0]=1;
        com[i][i]=1;
    }
    
    for(int i=1; i<51; ++i){
        for(int j=1; j<51; ++j){
            com[i][j] = com[i-1][j] + com[i-1][j-1];
        }
    }
    int N,A,B; cin >> N >> A >> B;
    map<ll,int> mp;
    REP(i, N){
        ll a;cin >> a;
        mp[a]++;
        v.push_back(a);
    }
    
    sort(all(v), greater<ll>());
    
    ll sum = 0;
    for(int i=0; i<A; ++i) sum += v[i];
    double ave = (double)sum / A;
    
    ll res = 0;
    int num = 0;
    for(int i=0; i<N; ++i) if(v[i] == v[A-1]) ++num;
    if(v[0] == v[A-1]){
        for(int j=A; j<=B; ++j){
            res += com[num][j];
        }
    }else{
        int a = 0;
        for(int i=0; i<A; ++i) if(v[i] == v[A-1]) ++a;
        res += com[num][a];
    }
    
    cout << ave << "\n" << res << endl;
    return 0;

}