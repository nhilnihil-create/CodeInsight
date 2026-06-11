#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);

    rep(i, N) {
        cin >> A.at(i) >> B.at(i);
    }

    int maxv = 0;
    int maxi;
    for (int i=0; i < N; i++) {
        if (maxv < A.at(i)) {
            maxv = A.at(i);
            maxi = i;
        }
    }
    cout << maxv + B.at(maxi) << endl;
}