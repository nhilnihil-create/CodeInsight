//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
constexpr ll LL_MAX = numeric_limits<ll>::max();
constexpr ull ULL_MAX = numeric_limits<ull>::max();

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

int main() {
    ll N;
    cin >> N;
    auto good_mod = [N](ll x){
        return (x%N + N) % N;
    };
    vector<ll> As(N);
    rep(i,0,N) {
        cin >> As[i];
    }
    vector<ll> Bs(N);
    rep(i,0,N) {
        Bs[i] = As[(i+1)%N] - As[i];
    }
    vector<ll> Cs(N);
    rep(i,0,N) {
        Cs[i] = Bs[(i+1)%N] - Bs[i];
    }
    // N == 1 or 2?
    rep(i,0,N) {
        if (Cs[i] % N != 0) {
            cout << "NO" << endl;
            return 0;
        }
        Cs[i] /= N;
    }
    ll cs_sum = 0;
    rep(i,0,N) {
        cs_sum += Cs[i];
    }
    if (cs_sum != 0) {
        cout << "NO" << endl;
        return 0;
    }
    ll as_sum = 0;
    rep(i,0,N) {
        as_sum += As[i];
    }
    ll inc = (N*(N+1))/2;
    if (as_sum % inc != 0) {
        cout << "NO" << endl;
        return 0;
    }
    ll op_cnt = as_sum / inc;
    ll Nx0 = op_cnt;
    rep(i,0,N) {
        Nx0 -= Cs[good_mod(-1+i)] * (i+1);
    }
    if (Nx0 % N != 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (Nx0 < 0) {
        cout << "NO" << endl;
        return 0;
    }
    ll x0 = Nx0 / N;
    vector<ll> cs_sums(N+1);
    rep(n,1,N+1) {
        cs_sums[n] = cs_sums[n-1] + Cs[n-1];
    }
    vector<ll> xs(N);
    xs[0] = x0;
    rep(i,1,N) {
        xs[i] = cs_sums[N-1] - cs_sums[i-1] + x0;
        if (xs[i] < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    ll ans = As[0];
    rep(i,1,N+1) {
        ans += (op_cnt - xs[good_mod(i)]) - (N-1) * xs[good_mod(i)];
        if (ans != As[good_mod(i)]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
