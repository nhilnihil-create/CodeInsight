#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    const ll MOD = 1e9+7;
    int N;
    cin >> N;
    vector<ll> x(N);
    for(auto& e: x) cin >> e;

    ll ans = 1;
    ll m = 0;
    for(auto& e: x){
        ans *= m+1;
        ans %= MOD;
        m = min(m+1, (e-1)/2+1);
    }

    cout << ans << endl;
}