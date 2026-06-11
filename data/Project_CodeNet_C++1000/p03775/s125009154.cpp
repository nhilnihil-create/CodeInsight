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

int max_digit(int x, int y) {
    return max(to_string(x).size(), to_string(y).size());
}

int main() {
    ll N;
    cin >> N;
    int ans = to_string(N).size();
    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) ans = min(ans, max_digit(i, N / i));
    }
    cout << ans << endl;
    return 0;
}