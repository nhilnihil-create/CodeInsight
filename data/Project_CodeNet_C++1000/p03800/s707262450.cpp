// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;

const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const int INF = (1LL << 60); // 1152921504606846976
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> inline T ceil(T a, T b) {return T((a + b - 1)/b);}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }

int nmax=200000; // 2*(10^5)
vvec g(nmax);



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n;
    string s;
    cin>>n>>s;
    s+=s[0];
    // cout<<s<<endl;
    n++;
    vector<string> a(4,"");
    a[0]+="SS";
    a[1]+="SW";
    a[2]+="WS";
    a[3]+="WW";
    rep(i,4){
        for(int j=1;j<n;j++){
            if(a[i][j]=='S'&&s[j]=='o'&&a[i][j-1]=='S') a[i]+="S";
            if(a[i][j]=='S'&&s[j]=='x'&&a[i][j-1]=='S') a[i]+="W";
            if(a[i][j]=='W'&&s[j]=='o'&&a[i][j-1]=='S') a[i]+="W";
            if(a[i][j]=='W'&&s[j]=='x'&&a[i][j-1]=='S') a[i]+="S";
            if(a[i][j]=='S'&&s[j]=='o'&&a[i][j-1]=='W') a[i]+="W";
            if(a[i][j]=='S'&&s[j]=='x'&&a[i][j-1]=='W') a[i]+="S";
            if(a[i][j]=='W'&&s[j]=='o'&&a[i][j-1]=='W') a[i]+="S";
            if(a[i][j]=='W'&&s[j]=='x'&&a[i][j-1]=='W') a[i]+="W";
        }
        if(a[i][0]==a[i][a[i].size()-2]&&a[i][1]==a[i][a[i].size()-1]){
            rep(j,a[i].size()-2){
                cout<<a[i][j];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}