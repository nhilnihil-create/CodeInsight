#include <bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;

ll n, p;
ll a[N], memo[5][N];
bool even, odd;

ll exp(ll a, ll b) {
    if(b == 1) return a;
    if(memo[a][b] != -1) return memo[a][b];
    if(b & 1) return memo[a][b] = exp(a, b / 2) * exp(a, b / 2) * a;
    else return memo[a][b] = exp(a, b / 2) * exp(a, b / 2);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(memo, -1, sizeof(memo));
    even = true, odd = false;
    for(ll i = 1; i <= n; i++) {
        if(a[i] % 2 == 1) {
            even = false;
            odd = true;
        }
    }
    if(even) {
        if(p == 0) cout << exp(2, n) << "\n";
        else cout << "0\n";
    } else if(odd) {
        cout << exp(2, n - 1) << "\n";
    }
}