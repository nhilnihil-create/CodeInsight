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

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {

    vector<string> S(3);

    cin >> S[0] >> S[1] >> S[2];

    char tmp;
    ll i = 0, j = 0, k = 0;

    tmp = S[0][i];

    while (1) {
        if (tmp == 'a') {
            tmp = S[0][i];
            i++;
            if (i > S[0].size()) {
                cout << 'A';
                break;
            }
            
        }
        else if (tmp == 'b') {
            tmp = S[1][j];
            j++;
            if (j > S[1].size()) {
                cout << 'B';
                break;
            }
            
        }
        else if (tmp == 'c') {
            tmp = S[2][k];
            k++;
            if (k > S[2].size()) {
                cout << 'C';
                break;
            }
        }
    }

    return 0;
}
