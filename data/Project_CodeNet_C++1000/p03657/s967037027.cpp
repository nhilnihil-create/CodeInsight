#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int A, B;
    cin >> A >> B;
    if (A % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    }
    if (B % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    }
    if ((A + B) % 3 == 0) {
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}
