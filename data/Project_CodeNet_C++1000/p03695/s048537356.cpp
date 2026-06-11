#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
// using ll = long long;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    bitset<8> s;

    int ex = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a / 400 >= 8)
            ex++;
        else
            s.set(a / 400);
    }

    if (s.count() == 0)
        cout << 1 << " ";
    else
        cout << s.count() << " ";
    cout << s.count() + ex << endl;
}