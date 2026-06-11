
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstring>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << endl

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-8;

const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector< vector<int> > g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g[--a].emplace_back(--b);
        g[b].emplace_back(a);
    }

    int q;
    cin >> q;

    vector<int> v(q), d(q), c(q);
    rep(i, q){
        cin >> v[i] >> d[i] >> c[i];
        --v[i];
    }

    vector< vector<int> > dp(n, vector<int>(11, -1));
    rep(i, q){
        dp[v[i]][d[i]] = i;
    }

    rreps(j, 10){
        rep(i, n){
            chmax(dp[i][j - 1], dp[i][j]);
            for(auto to : g[i]){
                chmax(dp[to][j - 1], dp[i][j]);
            }
        }
    }

    rep(i, n){
        if(dp[i][0] < 0){
            cout << 0 << endl;
        }else{
            cout << c[dp[i][0]] << endl;
        }
    }

    return 0;
}