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

    int n, m;
    cin >> n >> m;

    vector< vector<int> > v(m);
    rep(i, n){
        int x;
        cin >> x;
        v[x % m].emplace_back(x);
    }
    rep(i, m){
        SORT(v[i]);
    }

    int ans = 0;
    rep(i, m / 2 + 1){
        if(i == 0 || (m % 2 == 0 && i == m / 2)){
            ans += (int)v[i].size() / 2;
        }else{
            int j = (int)v[i].size();
            int k = (int)v[m - i].size();
            ans += min(j, k);
            int cnt = 0;
            if(j < k){
                REP(l, 1, v[m - i].size()){
                    if(v[m - i][l] == v[m - i][l - 1]){
                        ++cnt;
                        ++l;
                    }
                }
                ans += min(cnt, (k - j) / 2);
            }else if(j > k){
                REP(l, 1, v[i].size()){
                    if(v[i][l] == v[i][l - 1]){
                        ++cnt;
                        ++l;
                    }
                }
                ans += min(cnt, (j - k) / 2);
            }
        }
    }

    cout << ans << endl;

    return 0;
}