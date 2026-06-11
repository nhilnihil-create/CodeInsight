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
    int tmp = 0;
    int a;
    rep(i, N) {
        cin >> a;
        if (a % 2 == 1) tmp++;
    }
    if (tmp % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}
