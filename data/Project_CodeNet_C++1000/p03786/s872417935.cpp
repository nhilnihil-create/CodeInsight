#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> ma;
    rep(i, N) { cin >> A[i]; }

    sort(all(A));

    int cnt = 1;
    ll prev = 0;
    bool judge = 0;
    rep(i, N) {
        if (i != 0) {
            if (prev * 2 >= A[i])
                cnt++;
            else
                cnt = 1;
        }

        prev += A[i];
    }

    cout << cnt << endl;
}