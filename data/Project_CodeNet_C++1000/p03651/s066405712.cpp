#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a < b) swap(a,b);
    if (b == 0) return a;
    return a%b == 0 ? b : gcd(b, a%b);
}
int lcm(int a, int b) { return a*b/gcd(a,b);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    int g = A[0];
    int mx = A[0];
    for (int i=1;i<N;i++) {
        g = gcd(g,A[i]);
        mx = max(mx, A[i]);
    }
    if (K%g==0 && K <= mx) cout << "POSSIBLE" << "\n";
    else cout << "IMPOSSIBLE" << "\n";
}