#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a), 0LL)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
int const inf = 1e9;
ll const INF = 1e18;

inline void ios_(){cin.tie(0); ios::sync_with_stdio(false);}
template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}



signed main(){
    int n, m;
    cin >> n >> m;
    vector<deque<int>> v(n, deque<int>(m));
    REP(i, n){
        REP(j, m){
            cin >> v[i][j];
            v[i][j]--;
        }
    }

    int ans = n;
    vector<bool> del(m, false);

    while(!v[0].empty()){
        vector<int> cnt(m);
        bool finish = false;
        REP(i, n){
            while(!v[i].empty() && del[v[i][0]]){
                v[i].pop_front();
            }
            if(v[i].empty()){
                finish = true;
                break;
            }
            cnt[v[i][0]]++;
        }

        if(finish) break;

        int ma = -1, p = 0;
        REP(i, m){
            if(chmax(ma, cnt[i])) p = i;
        }

        chmin(ans, ma);
        del[p] = true;
    }

    cout << ans << endl;

    return 0;
}
