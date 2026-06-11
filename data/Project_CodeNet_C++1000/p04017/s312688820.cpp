#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, L, Q;
    cin >> N;
    vector<ll> x(N);
    REP(i,N) cin >> x[i];
    x.push_back(LINF);
    cin >> L >> Q;
    vector<vector<int>> to(22, vector<int>(N));
    REP(i,N){
        auto itr = lower_bound(x.begin(), x.end(), L+x[i]);
        if(*itr - x[i] > L) itr--;
        to[0][i] = itr - x.begin();
    }
    REP(i,20) REP(j,N) to[i+1][j] = to[i][to[i][j]];

    while(Q--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        int ans = 0;
        if(a > b) swap(a,b);
        for(int i=20;i>=0;i--) if(to[i][a] < b){
            a = to[i][a];
            ans += 1 << i;
        }
        cout << ans + 1 << endl;
    }
}