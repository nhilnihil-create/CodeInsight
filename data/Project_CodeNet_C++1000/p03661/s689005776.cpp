#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<long long> S(N);
    cin >> S[0];
    for (int i = 1; i < N; i++) {
        int a; cin >> a;
        S[i] = S[i - 1] + a;
    }
    long long ans = 1e18;
    for (int i = 0; i < N - 1; i++) {
        ans = min(ans, abs(S[N - 1] - 2 * S[i]));
    }
    cout << ans << endl;
}

