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
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

int N;
int A[310][310], dist[310][310];
 
signed main() {
    cin >> N;
    rep(i,0,N) rep(j,0,N) {
        cin >> A[i][j];
        dist[i][j] = A[i][j];
    }

    rep(k,0,N) rep(i,0,N) rep(j,0,N) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }

    // No
    rep(i,0,N) rep(j,0,N) {
        if(dist[i][j] != A[i][j]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Yes
    int ans = 0;
    rep(i,0,N) rep(j,0,N) {
        bool ok = true;
        rep(k,0,N) {
            if(k == i || k == j) continue;
            int va = dist[i][j];
            int vb = dist[i][k] + dist[k][j];
            if(va == vb) ok = false;
        }
        if(ok) ans += dist[i][j];
    }
    cout << ans / 2 << endl;
    return 0;
}