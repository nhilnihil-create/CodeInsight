#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

#define INF 1e9
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
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> a(n);
    rep(i, n) cin >> x.at(i) >> y.at(i) >> a.at(i);
    vector<vector<bool>> white(h, vector<bool> (w, true));
    rep(i, n) {
        if (a.at(i) == 1) {
            rep(k, x.at(i)) {
                rep(j, h) {
                    white.at(j).at(k) = false;
                }
            }
        }
        else if (a.at(i) == 3) {
            rep(k, y.at(i)) {
                rep(j, w) {
                    white.at(k).at(j) = false;
                }
            }
        }
        else if (a.at(i) == 2) {
            for (int k = x.at(i); k < w; k++) {
                rep(j, h) {
                    white.at(j).at(k) = false;
                }
            }
        }
        else if (a.at(i) == 4) {
            for (int k = y.at(i); k < h; k++) {
                rep(j, w) {
                    white.at(k).at(j) = false;
                }
            }
        }
    }
    int count = 0;
    rep(i, h) {
        rep(j, w) {
            if (white.at(i).at(j)) {
                count++;
            }
        }
    }
    cout << count << endl;
}