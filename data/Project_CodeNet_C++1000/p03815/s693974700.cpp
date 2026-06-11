#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    ll x;
    cin >> x;
    ll set = (x + 10) / 11;
    ll y = 11 * (set - 1) + 6;
    if (y >= x) cout << 2 * (set - 1) + 1;
    else cout << 2 * set;
    return 0;
}