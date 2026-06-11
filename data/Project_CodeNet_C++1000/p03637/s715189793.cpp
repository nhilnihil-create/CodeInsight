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

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt4 = 0;
    rep(i, N) {
        if (A[i] % 4 == 0) {
            cnt4++;
        } else if (A[i] % 2 == 0) {
            cnt2++;
        } else {
            cnt1++;
        }
    }

    if (cnt2 != 0) cnt1++;

    if (cnt4 >= cnt1 - 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}