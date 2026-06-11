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

int factorial(int N) {
    int ans = 1;
    for (int i = 2; i <= N; i++) ans = (ll)ans * i % 1000000007;
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    int dif = abs(N - M);
    cout << (ll)factorial(N) * factorial(M) * max(0, (2 - dif)) % 1000000007 << endl;
    return 0;
}