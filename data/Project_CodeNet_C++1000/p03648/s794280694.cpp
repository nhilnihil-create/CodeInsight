#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {

    ll K;
    cin >> K;
    ll N = 50;
    vector<ll> a(N), b(N);

    rep(i,N) {
        if (K % N > i) b[i] = K / N + 1;
        else b[i] = K / N;
        a[i] = (N - 1) + N * b[i] - (K - b[i]);
    }

    cout << N << endl;
    rep(i,N) {
        cout << a[i];
        if (i < N - 1) cout << " ";
        else cout << endl;
    }
    
    return 0;
}