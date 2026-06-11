#include "bits/stdc++.h"
using namespace std;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    if (N > M / 2) cout << M / 2 << endl;
    else cout << N + (M - 2 * N) / 4 << endl;
    return 0;
}