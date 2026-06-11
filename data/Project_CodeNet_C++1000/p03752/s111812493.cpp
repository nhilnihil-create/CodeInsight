#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(obj) obj.begin(), obj.end()

template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const int iINF = 1e9;
const long long llINF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

int main() { 
    int N, K;
    cin >> N >> K;
    vector<long long> a(N);
    REP(i, N) {
        cin >> a[i];
    }

    int S = 1 << N;
    long long ans = llINF;
    REP(ss, S) {
        long long tmp = 0, h = 0;
        int cnt = 0;
        REP(i, N) {
            if ((ss >> i) & 1) {
                cnt += 1;
            }
        }

        if (cnt < K) {
            continue;
        }

        REP(i, N) {
            if ((ss >> i) & 1) {
                if (h >= a[i]) {
                    tmp += h + 1 - a[i];
                    h += 1;
                } else {
                    h = a[i];
                }
            } else {
                h = max(h, a[i]);
            }
        }

        ans = min(tmp, ans);
    }

    cout << ans << endl;
    return 0; 
}