#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    map<int, int> A;
    rep(i, N) {
        int tmp;
        cin >> tmp;
        A[tmp]++;
    }

    vector<ll> B;
    for (auto x : A) {
        int y = x.second;

        while (y >= 2) {
            B.push_back(x.first);
            y -= 2;
        }
    }

    if (B.size() < 2) {
        cout << 0 << endl;
    } else {
        sort(B.begin(), B.end());
        reverse(B.begin(), B.end());

        ll ans = B[0] * B[1];

        cout << ans << endl;
    }
}