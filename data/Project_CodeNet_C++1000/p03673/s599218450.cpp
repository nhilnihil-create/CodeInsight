#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    deque<int> b;
    if(n % 2 == 0) {
        rep(i, n) {
            int a;
            cin >> a;
            if(i % 2 == 0) {
                b.push_back(a);
            }
            else b.push_front(a);
        }
    }
    else {
        rep(i, n) {
            int a;
            cin >> a;
            if(i % 2 == 1) {
                b.push_back(a);
            }
            else b.push_front(a);
        }
    }
    rep(i, n-1) cout << b[i] << " ";
    cout << b[n - 1] << endl;
    return 0;
}
