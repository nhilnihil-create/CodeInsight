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

    string s, t;
    cin >> s >> t;

    int n = (int)s.size();
    int m = (int)t.size();

    vector<int> sa(n + 1), sb(n + 1);
    vector<int> ta(n + 1), tb(n + 1);

    rep(i, n){
        sa[i + 1] = s[i] == 'A';
        sb[i + 1] = s[i] == 'B';
        sa[i + 1] += sa[i];
        sb[i + 1] += sb[i];
    }

    rep(i, m){
        ta[i + 1] = t[i] == 'A';
        tb[i + 1] = t[i] == 'B';
        ta[i + 1] += ta[i];
        tb[i + 1] += tb[i];
    }

    int q;
    cin >> q;
    vector<bool> ans;

    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a;
        --c;
        int tsa = sa[b] - sa[a];
        int tsb = sb[b] - sb[a];
        int tta = ta[d] - ta[c];
        int ttb = tb[d] - tb[c];
        int ms = ((tsa - tsb) % 3 + 3) % 3;
        int mt = ((tta - ttb) % 3 + 3) % 3;
        ans.emplace_back(ms == mt);
    }

    rep(i, ans.size()){
        if(ans[i]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}