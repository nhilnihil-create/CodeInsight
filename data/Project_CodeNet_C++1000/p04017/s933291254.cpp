#include<algorithm>
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

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

template<typename T>
bool chmax(T &a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T &a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> x(n);
    rep(i, n){
        cin >> x[i];
    }

    int l;
    cin >> l;

    vector< vector<int> > v(18, vector<int>(n, 0));
    rep(i, n){
        v[0][i] = upper_bound(x.begin(), x.end(), x[i] + l) - x.begin() - 1;
    }

    rep(i, 17){
        rep(j, n){
            v[i + 1][j] = v[i][v[i][j]];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if(a > b){
            swap(a, b);
        }

        int ans = 0, now = a;
        while(now < b){
            rrep(i, 18){
                if(v[i][now] < b || i == 0){
                    now = v[i][now];
                    ans += (1 << i);
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}