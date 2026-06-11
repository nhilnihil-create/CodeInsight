#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    Rep (i, N) Rep (j, N) cin >> A[i][j];

    vector<vector<bool>> need(N, vector<bool>(N, true));
    Rep (k, N) Rep (i, N) Rep (j, N) {
        if (A[i][j] > A[i][k] + A[k][j]) {
            cout << -1 << endl;
            return 0;
        } else if (A[i][j] == A[i][k] + A[k][j] && A[i][k] > 0 && A[k][j] > 0) {
            need[i][j] = false;
        }
    }

    ll ans = 0;
    Rep (i, N) {
        for (ll j = i+1; j < N; j++) {
            if (need[i][j]) ans += A[i][j];
        }
    }

    cout << ans << endl;

}