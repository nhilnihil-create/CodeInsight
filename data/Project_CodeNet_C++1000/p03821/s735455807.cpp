#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N){
        cin >> A[i] >> B[i];
    }

    ll ans = 0;
    for (int i = N-1; i >= 0; i--){
        ll a = A[i] + ans;
        ll x = B[i] - (a % B[i]);
        if(x == B[i])x = 0;
        ans += x;
    }

    cout << ans << endl;

    return 0;
}