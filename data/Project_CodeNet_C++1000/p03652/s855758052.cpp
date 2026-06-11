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
typedef vector<ll>vec;
typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


bool ng[333];
int A[333][333];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    REP(i,N) REP(j,M) cin >> A[i][j], A[i][j]--;

    int ans = INF;
    REP(x,M){
        vector<int> cnt(M);
        REP(i,N){
            REP(j,M){
                if(!ng[A[i][j]]){
                    cnt[A[i][j]]++;
                    break;
                }
            }
        }
        int ma = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        chmin(ans, cnt[ma]);
        ng[ma] = true;
    }
    cout << ans << endl;
}