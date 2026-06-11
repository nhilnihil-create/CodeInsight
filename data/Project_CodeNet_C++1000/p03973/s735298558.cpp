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
    int N;
    cin >> N;
    vector<ll> A(N);
    for(auto& x: A) cin >> x;

    ll p = 2;
    ll ans = A[0]-1;
    for(int i=1; i<N; i++){
        if(p == A[i]) p++;
        else ans += (A[i]-1)/p;
    }

    cout << ans << endl;
}