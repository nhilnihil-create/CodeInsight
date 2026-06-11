#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;

    rep(i, h) {
        rep(j, w) {
            string s;
            cin >> s;

            if(s == "snuke") {
                int t = 0;
                for(char c = 'A'; c <= 'Z'; c++) {
                    if(t == j) {
                        cout << c << i+1 << endl;
                        return 0;
                    }
                    t++;
                }
            }
        }
    }

    cout << endl;
    return 0;
}