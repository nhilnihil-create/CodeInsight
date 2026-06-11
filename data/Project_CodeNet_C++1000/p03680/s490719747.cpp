#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
using ll = long long;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N,0);
    rep(i, N) cin >> a.at(i);
    rep(i, N) a.at(i)--;
    
    vector<int> flag(N, 0);
    int temp = 0, sum = 0;

    rep(i, N) {
        if (flag.at(a.at(temp)) == 0) {
            flag.at(temp)++, sum++;
            temp = a.at(temp);
        }else {
            cout << -1 << endl;
            return 0;
        }

        if (temp == 1) {
            cout << sum << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
