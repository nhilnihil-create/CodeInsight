#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> cnt(100001);
    Rep(i, N) {
        int a, b;
        cin >> a >> b;
        cnt[a] += b;
    }
    ll count = 0;
    Rep(i, 100001) {
        count += cnt[i];
        if (count >= K) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}