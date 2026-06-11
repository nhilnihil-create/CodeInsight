#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N;
    cin >> N;
    vi S(N);
    rep(i, N) {
        cin >> S[i];
    }

    int sum = 0;
    rep(i, N) {
        sum += S[i];
    }
    
    if (sum % 10 != 0) {
        cout << sum << endl;
        return 0;
    }

    sort(S.begin(), S.end());

    bool ok = false;
    for (int i = 0; i < N; i++) {
        if (S[i] % 10 != 0) {
            ok = true;
            sum -= S[i];
            break;
        }
    }

    if (ok) {
        cout << sum << endl;
    } else {
        cout << 0 << endl;
    }
}