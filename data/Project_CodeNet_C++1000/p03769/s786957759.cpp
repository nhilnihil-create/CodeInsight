// 基本テンプレート

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

signed main() {
    int N; cin >> N; N++;
    int cnt_one = __builtin_popcount(N);

    bool first = true;
    vector<int> ans;
    int rec = 0;
    repr(i,60,0) {
        if(N >> i & 1) {
            if(first) {
                first = false;
                ans.resize(i);
                iota(ans.begin(), ans.end(), 1);
                rec = ans.size();
                rep(k,0,rec) ans.push_back(ans[k]);
            }
            else {
                ans.insert(ans.begin()+i, ++rec);
                ans.push_back(rec);
            }
        }
    }
    cout << ans.size() << endl;
    rep(i,0,ans.size()) {
        if(i != 0) printf(" ");
        printf("%lld", ans[i]);
    }
    cout << endl;
    return 0;
}