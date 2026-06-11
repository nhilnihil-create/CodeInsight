#include<algorithm>
#include<bitset>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = (int)(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = (int)(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define REVERSE(x) reverse((x).begin(), (x).end())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << '\n'
#define endl '\n'

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-10;

constexpr int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
constexpr int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<typename T>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

int n, m;
int a[300][300];
bool s[300];

int solve(void){
    int cnt[300];
    fill(cnt, cnt + m, 0);

    int res = -1, id = -1;
    rep(i, n){
        for(auto j : a[i]){
            if(s[j]){
                ++cnt[j];
                if(chmax(res, cnt[j])){
                    id = j;
                }
                break;
            }
        }
    }

    if(id == -1){
        return n;
    }

    s[id] = false;

    return min(res, solve());
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    cin >> n >> m;

    rep(i, n){
        rep(j, m){
            cin >> a[i][j];
            --a[i][j];
        }
    }

    fill(s, s + m, true);

    int ans = solve();
    cout << ans << endl;

    cout << flush;

    return 0;
}