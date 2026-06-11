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

    ll N;
    cin >> N;
    vec A(N), dif(N);
    ll s = 0;
    Rep (i, N) {
        cin >> A[i];
        s += A[i];
        if (i > 0) {
            dif[i-1] = A[i] - A[i-1];
        }
    }
    dif[N-1] = A[0] - A[N-1];

    if (s % (N*(N+1)/2) > 0) {
        cout << "NO\n";
        return 0;
    }

    ll cnt = s / (N*(N+1)/2);

    Rep (i, N) {
        dif[i] -= cnt;
    }

    Rep (i, N) {
        if (dif[i] > 0) {
            cout << "NO\n";
            return 0;
        }
        dif[i] *= -1;
        if (dif[i] % N > 0) {
            cout << "NO\n";
            return 0;
        }

        cnt -= dif[i] / N;
    }

    if (cnt == 0) {
        cout << "YES\n";
        return 0;
    } else {
        cout << "NO\n";
        return 0;
    }


}