#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (b - a == c - b) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
