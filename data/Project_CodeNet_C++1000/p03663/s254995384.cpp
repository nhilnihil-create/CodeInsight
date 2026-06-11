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
    int digit = -1;
    rep(i,0,12) {
        int val = 1;
        rep(j,0,i) val *= 10;
        printf("? %lld\n", val);
        fflush(stdout);
        char c; cin >> c;
        if(c == 'N') {
            digit = i-1;
            break;
        }
    }

    if(digit == -1) {
        rep(i,0,12) {
            int val = 2;
            rep(j,0,i) val *= 10;
            printf("? %lld\n", val);
            fflush(stdout);
            char c; cin >> c;
            if(c == 'Y') {
                digit = i;
                break;
            }
        }
        int ans = 1;
        rep(i,0,digit) ans *= 10;
        printf("! %lld\n", ans);
        return 0;
    }

    int ub = 1, lb = 1;
    rep(i,0,digit) lb *= 10;
    rep(i,0,digit+1) ub *= 10;
    ub--;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        printf("? %lld\n", mid*10);
        fflush(stdout);
        char c; cin >> c;
        if(c == 'Y') ub = mid;
        else lb = mid;
    }
    printf("! %lld\n", ub);
    fflush(stdout);
    return 0;
}