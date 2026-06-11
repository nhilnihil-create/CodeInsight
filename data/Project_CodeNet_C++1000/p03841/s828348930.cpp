#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void Main(){
    int N; cin >> N;
    VI x(N); REP(i,N) cin >> x[i];
    VI p(N); REP(i,N) p[i] = i;

    auto comp = [&](int i, int j){return x[i]<x[j];};
    sort(ALL(p), comp);

    VI a(N*N,-1);
    REP(i,N) a[x[i]-1] = i+1;

    int ptr = 0;
    for(int i : p){
        REP(_,i){
            while(ptr<N*N && a[ptr]!=i+1 && a[ptr]!=-1) ptr++;
            if(a[ptr]==i+1){
                cout << "No" << en;
                return;
            }
            else{
                a[ptr++] = i+1;
            }
        }
    }

    ptr = N*N-1;
    REVERSE(p);
    for(int i : p){
        REP(_,N-1-i){
            while(0<=ptr && a[ptr]!=i+1 && a[ptr]!=-1) ptr--;
            if(a[ptr]==i+1){
                cout << "No" << en;
                return;
            }
            else{
                a[ptr--] = i+1;
            }
        }
    }

    cout << "Yes" << en;
    REP(i,N*N) cout << a[i] << " ";
    return;
}

int main(void){
    cin.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t){
        Main();
    }
    return 0;
}