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

    vi ans;
    for (int i = N - 1; i >= 0; i -= 2) {
        ans.push_back(A[i]);
    }
    if (N % 2 == 0) { 
        for (int i = 0; i < N; i += 2) {
            ans.push_back(A[i]);
        }
    } else {
        for (int i = 1; i < N; i += 2) {
            ans.push_back(A[i]);
        }
    }

    rep(i, ans.size()) {
        cout << ans[i];
        if (i != ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}