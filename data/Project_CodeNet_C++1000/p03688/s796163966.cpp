#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::vector<long long> a) {
    long long mn = *min_element(a.begin(), a.end());
    long long mx = *max_element(a.begin(), a.end());
    long long d = mx - mn;
    if (d == 0) {
        long long x = a[0];
        if (x == N - 1) {
            cout << YES << endl;
            return;
        }
        if (x >= 1 && x <= N / 2) {
            cout << YES << endl;
            return;
        }
        cout << NO << endl;
    } else if (d == 1) {
        long long cmn = count(a.begin(), a.end(), mn);
        long long cmx = count(a.begin(), a.end(), mx);
        if ( (mx - cmn) >= 1 && (mx - cmn) * 2 <= cmx) {
            cout << YES << endl;
            return;
        }
        cout << NO << endl;
    } else {
        cout << NO << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
