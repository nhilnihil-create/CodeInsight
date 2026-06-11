//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll INF = 1000000000000007;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

typedef struct _Edge{
    int from;
    int to;
    ll cost;
}Edge;

int main(void){
    int N,M;
    cin >> N >> M;
    Edge edge[M];
    REP(i,M){cin >> edge[i].from >> edge[i].to >> edge[i].cost;
        edge[i].from--;
        edge[i].to--;
        edge[i].cost *= -1;
    }

    ll dist[N];
    for(int i=0; i<N; i++) dist[i] = INF;
    dist[0] = 0;

    for(int i=0; i<N-1; i++)
        for(int j=0; j<M; j++)
            chmin(dist[edge[j].to], dist[edge[j].from] + edge[j].cost);

    bool flag[N];
    REP(i,N) flag[i] = true;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(chmin(dist[edge[j].to], dist[edge[j].from] + edge[j].cost)) flag[edge[j].to] = false;
            if(flag[edge[j].from] == false) flag[edge[j].to] = false;
        }

    if(flag[N-1]) cout << -dist[N-1] << endl;
    else cout << "inf" << endl;

    return 0;
}