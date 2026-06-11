#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, x;
    cin >> N >> x;

    if (N == 2) {
        if (x == 2) {
            cout << "Yes\n1\n2\n3\n";
        } else {
            cout << "No\n";
        }
        return 0;
    }

    if (x == 1 || x == 2*N-1) {
        cout << "No\n";
        return 0;
    }

    vec ans(2*N-1, -1);
    if (x == 2) {
        ans[N-3] = 3;
        ans[N-2] = 1;
        ans[N-1] = 2;
        ans[N] = 4;
        ll tmp = 5;
        Rep (i, 2*N-1) {
            if (N-3 <= i && i <= N) continue;
            if (ans[i] == -1) {
                ans[i] = tmp++;
            }
        }
    } else {
        ans[N-3] = x-2;
        ans[N-2] = x+1;
        ans[N-1] = x;
        ans[N] = x-1;
        ll tmp = 1;
        Rep (i, 2*N-1) {
            if (N-3 <= i && i <= N) continue;
            if (x-2 <= tmp && tmp <= x-1) tmp = x+2;
            ans[i] = tmp;
            tmp++;
        }
    }

    cout << "Yes\n";
    Rep (i, 2*N-1) {
        cout << ans[i] << "\n";
    }
}