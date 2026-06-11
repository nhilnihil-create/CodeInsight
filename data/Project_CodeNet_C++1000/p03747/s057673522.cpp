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

int N, L, T;
int x[100010], w[100010];
int calc(int a, int b) {
    int s = x[a], t = x[b];
    int dist = (w[a] == 1 ? (t-s+L)%L : (s-t+L)%L);
    if(2*T < dist) return 0;
    return (2*T - dist) / L + 1;
}

signed main() {
    vector<pii> pos;
    cin >> N >> L >> T;
    rep(i,0,N) {
        cin >> x[i] >> w[i];
        if(w[i] == 1) pos.push_back(make_pair( (x[i]+T)%L, i ));
        if(w[i] == 2) pos.push_back(make_pair( (x[i]-(T%L)+L)%L, -i ));
    }
    sort(pos.begin(), pos.end());
    
    int diff = 0, idx = 0;
    rep(i,1,N) if(w[0] != w[i]) diff += calc(0, i);
    diff %= N;
    if(w[0] == 2) diff *= -1;
    while(pos[idx].second != 0) idx++;

    rep(i,0,N) printf("%lld\n", pos[(idx+i-diff+N)%N].first);
    return 0;
}