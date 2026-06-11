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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;

    vector<lint> a(n);
    rep(i, n){
        cin >> a[i];
    }

    lint ans = 0LL;
    lint maxi = 0LL;
    rep(i, n){
        lint c = (a[i] - 1LL) / (maxi + 1LL);
        ans += c;
        if(a[i] > maxi + 1LL){
            a[i] = 1LL;
        }else{
            a[i] -= c * (maxi + 1LL);
        }
        chmax(maxi, a[i]);
    }

    cout << ans << endl;

    cout << flush;

    return 0;
}