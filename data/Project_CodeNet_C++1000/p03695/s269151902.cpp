#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) {
        cin >> A[i];
    }

    int cnt = 0;
    int cnt2 = 0;
    vector<bool> x(8);
    rep(i, N) {
        if (A[i] >= 3200) {
            cnt2++;
            continue;
        }

        if (A[i] <= 399) {
            if (!x[0]) {
                cnt++;
                x[0] = true;
            }
        } else if (A[i] <= 799) {
            if (!x[1]) {
                cnt++;
                x[1] = true;
            }
        } else if (A[i] <= 1199) {
            if (!x[2]) {
                cnt++;
                x[2] = true;
            }
        } else if (A[i] <= 1599) {
            if (!x[3]) {
                cnt++;
                x[3] = true;
            }
        } else if (A[i] <= 1999) {
            if (!x[4]) {
                cnt++;
                x[4] = true;
            }
        } else if (A[i] <= 2399) {
            if (!x[5]) {
                cnt++;
                x[5] = true;
            }
        } else if (A[i] <= 2799) {
            if (!x[6]) {
                cnt++;
                x[6] = true;
            }
        } else if (A[i] <= 3199) {
            if (!x[7]) {
                cnt++;
                x[7] = true;
            }
        }
    }

    if (cnt == 0 && cnt2 != 0) {
        cout << 1;
    } else {
        cout << cnt;
    }
    cout << " ";
    if (cnt2 == 0) {
        cout << cnt;
    } else {
        cout << (cnt + cnt2);
    }
    cout << endl;
}