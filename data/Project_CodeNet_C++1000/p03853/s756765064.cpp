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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char> (w));
    rep(i, h) {
        rep(j, w) {
            cin >> c.at(i).at(j);
        }
    }
    rep(i, h) {
        rep(k, 2) {
            rep(j, w) {
                cout << c.at(i).at(j);
            }
            cout << endl;
        }
    }
}