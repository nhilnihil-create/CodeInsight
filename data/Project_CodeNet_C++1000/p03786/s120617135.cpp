#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    sort(all(A));

    ll sum = 0;
    ll res = 1;
    rep(i, N - 1) {
        sum += A[i];
        if (A[i + 1] <= sum * 2)
            res++;
        else
            res = 1;
    }

    cout << res << endl;
}