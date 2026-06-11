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
    string S;
    cin >> S;
    int ans = 0;
    char now = S[0];
    for (int i = 1; i < S.size(); i++) {
        if (S[i] != now) {
            ans++;
            now = S[i];
        }
    }
    cout << ans << endl;
    return 0;
}