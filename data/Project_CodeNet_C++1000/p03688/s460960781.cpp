#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[0] == a[N - 1]) {
        if (a[0] == N - 1 || a[0] <= N / 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (a[0] + 1 < a[N - 1]) {
        cout << "No" << endl;
    } else {
        int i = 0;
        while (a[i] == a[0]) i++;
        if (a[0] >= i && a[0] < i + (N - i) / 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}