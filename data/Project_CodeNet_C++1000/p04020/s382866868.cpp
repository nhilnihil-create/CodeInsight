#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    ll ans = 0;
    int prev = 0;
    for (int i=0;i<N;i++){
        if (prev <= A[i]) {
            ans += prev;
            A[i] -= prev;
            ans += A[i]/2;
            prev = A[i]%2;
        } else {
            ans += A[i];
            prev = 0;
        }
    }
    cout << ans << "\n";
}