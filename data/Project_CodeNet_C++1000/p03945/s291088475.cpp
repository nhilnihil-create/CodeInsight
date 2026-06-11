#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

    string S;

    cin >> S;

    ll N = S.size(), tmp = 0;
    vector<ll>C;
    char l = 'A';

    rep(i, N) {
        if (i == 0) {
            tmp++;
            l = S[i];
        }
        else if (S[i] == l) {
            tmp++;
            if (i == N - 1) {
                C.push_back(tmp);
            }
        }
        else {
            l = S[i];
            C.push_back(tmp);
            tmp = 1;
            if (i == N - 1) {
                C.push_back(tmp);
            }
        }
    }


    ll ans;
    
    if (N == 1) {
        ans = 0;
    }
    else {
        ans = C.size() - 1;
    }

    cout << ans;

    return 0;
}
