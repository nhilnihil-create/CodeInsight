#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N;
    cin >> N;
    int A[N + 1];
    rep(i, N) cin >> A[i + 1];
    int ans = 0;
    rep(i, N) {
        if (A[A[i + 1]] == i + 1) ans++;
    }
    cout << ans / 2 << endl;



    return 0;
}
