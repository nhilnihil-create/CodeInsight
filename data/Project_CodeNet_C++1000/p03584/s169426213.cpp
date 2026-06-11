#include<algorithm>
#include<cassert>
#include<cfloat>
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

constexpr int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
constexpr int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<typename T>
bool chmax(T& a, T b, bool equal = false){
    if(a < b || equal && a == b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b, bool equal = false){
    if(b < a || equal && a == b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<lint> b(n);
    rep(i, n){
        cin >> a[i] >> b[i];
    }

    lint ans = 0;
    int tmp = 0;
    lint val = 0;
    rep(i, 31){
        if(k >> i & 1){
            tmp = 0;
            val = 0;
            for(int j = 30 ; j > i ; --j){
                tmp |= (k >> j & 1) << j;
            }
            for(int j = 0 ; j < i ; ++j){
                tmp |= 1 << j;
            }
            rep(j, n){
                if((a[j] | tmp) <= tmp){
                    val += b[j];
                }
            }
            chmax(ans, val);
        }
    }

    tmp = k;
    val = 0;
    rep(j, n){
        if((a[j] | tmp) <= tmp){
            val += b[j];
        }
    }
    chmax(ans, val);

    cout << ans << endl;

    return 0;
}