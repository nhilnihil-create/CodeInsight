#include "math.h"
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define ifor(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long double ld;
typedef long long int lli;

lli n;
string str[2] = {"First", "Second"};
void solve(vector<lli> a, lli depth)
{
    bool flag = false;
    int odd = 0, even = 0;
    rep(i, n)
    {
        if (a[i] == 1) {
            flag = true;
        }
        if (a[i] & 1) {
            odd++;
        } else {
            even++;
        }
    }
    if (flag) {
        lli sum = 0;
        rep(i, n)
        {
            sum += a[i] - 1;
        }
        if (sum & 1) {
            cout << str[depth % 2] << endl;
        } else {
            cout << str[(depth + 1) % 2] << endl;
        }
        exit(0);
    }
    if (even % 2 == 1) {
        cout << str[(depth) % 2] << endl;
        exit(0);
    } else if (odd != 1) {
        cout << str[(depth + 1) % 2] << endl;
        exit(0);
    } else {
        rep(i, n) if (a[i] % 2) a[i]--;
        lli g = a[0];
        rep(i, n) g = __gcd(g, a[i]);
        rep(i, n) a[i] /= g;
        solve(a, depth + 1);
    }
}
int main()
{
    cin >> n;
    vector<lli> a(n, 0);
    rep(i, n) cin >> a[i];
    solve(a, 0);
}
