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

int N, M, K;
int x[100010], a[100010];

vector<int> mul(vector<int> &a, vector<int> &b) {
    int S = a.size();
    vector<int> ret(S);
    rep(i,0,S) ret[i] = a[b[i]];
    return ret;
}

signed main() {
    cin >> N;
    rep(i,0,N) cin >> x[i];
    vector<int> diff(N-1);
    rep(i,1,N) diff[i-1] = x[i] - x[i-1];

    cin >> M >> K;
    vector<int> swp(N-1);
    iota(swp.begin(), swp.end(), 0);
    rep(i,0,M) {
        int val; cin >> val; val--;
        swap(swp[val-1], swp[val]);
    }

    while(K) {
        if(K & 1) diff = mul(diff, swp);
        swp = mul(swp, swp);
        K >>= 1;
    }

    int ans = x[0];
    rep(i,0,N) {
        if(i == 0) cout << ans << endl;
        else {
            ans += diff[i-1];
            cout << ans << endl;
        }
    }
    return 0;
}