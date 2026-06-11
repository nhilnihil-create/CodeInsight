#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<pair<int, int>> A;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        A.push_back(make_pair(a, b));
    }

    sort(A.begin(), A.end(), [](const auto &x, const auto &y) {
        return x.first < y.first;
    });

    int i = 0;
    while (K > 0) {
        K -= A[i].second;
        i++;
    }

    cout << A[i - 1].first << endl;
}