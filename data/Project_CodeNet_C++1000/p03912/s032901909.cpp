#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> cnt(101010), cnt_mod(M);
    REP(i,N){
        int X;
        cin >> X;
        cnt_mod[X%M]++;
        cnt[X]++;
    }
    int ans = 0;
    REP(i,M){
        if(i == 0 || 2 * i == M){
            ans += cnt_mod[i] / 2;
            cnt_mod[i] %= 2;
        }
        else{
            int p = min(cnt_mod[i], cnt_mod[M-i]);
            ans += p;
            cnt_mod[i] -= p, cnt_mod[M-i] -= p;
            for(int j=i;j<101010;j+=M){
                ans += min(cnt_mod[i], cnt[j]) / 2;
                cnt_mod[i] -= min(cnt_mod[i], cnt[j]) / 2 * 2;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}