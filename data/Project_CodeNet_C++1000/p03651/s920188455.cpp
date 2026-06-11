#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x % y);
}

int main() {
    int N, K; cin >> N >> K;
    int A[N];
    rep(i, N) cin >> A[i];
    if(K > *max_element(A, A + N)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int ans = 0;
    rep(i, N) ans = gcd(A[i], ans);
    if(K % ans == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}