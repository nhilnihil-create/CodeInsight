#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char> (n));
    vector<vector<char>> b(m, vector<char> (m));
    rep(i, n) {
        rep(j, n) {
            cin >> a.at(i).at(j);
        }
    }
    rep(i, m) {
        rep(j, m) {
            cin >> b.at(i).at(j);
        }
    }
    rep(i, n - m + 1) {
        rep(j, n - m + 1) {
            rep(k, m) {
                rep(h, m) {
                    if (a.at(k + i).at(h + j) != b.at(k).at(h)) {
                        goto next;
                    }
                }
            }
            goto last;
            next:;
        }
    }
    cout << "No" << endl;
    return 0;
    last:
    cout << "Yes" << endl;
}