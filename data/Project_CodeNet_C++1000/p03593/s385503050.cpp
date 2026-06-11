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

    vector<int> count(26);  // count[i] : i番目のアルファベット(iは0-index)が何個含まれるか

    rep(i, h) {
        rep(j, w) {
            char c;
            cin >> c;
            count[c - 'a']++;
        }
    }

    int g1, g2, g4;
    
    if(h%2 == 1 && w%2 == 1) {
        g1 = 1;
    }
    else {
        g1 = 0;
    }

    if(h%2 == 1 && w%2 == 1) {
        g2 = h/2 + w/2;
    }
    else if(h%2 == 1 && w%2 == 0) {
        g2 = w/2;
    }
    else if(h%2 == 0 && w%2 == 1) {
        g2 = h/2;
    }
    else if(h%2 == 0 && w%2 == 0) {
        g2 = 0;
    }

    g4 = (h/2)*(w/2);

    rep(loop, g1) {
        rep(i, 26) {
            if(count[i]%2 == 1) {
                count[i]--;
                break;
            }
        }
    }
    
    if(h == 1 || w == 1) {
        rep(loop, g2) {
            rep(i, 26) {
                if(count[i] > 0 && count[i]%2 == 0) {
                    count[i] -= 2;
                    break;
                }
            }
        }
    }
    else {
        rep(loop, g2) {
            rep(i, 26) {
                if(count[i]%4 == 2) {
                    count[i] -= 2;
                    break;
                }
            }
        }
    }

    rep(loop, g4) {
        rep(i, 26) {
            if(count[i] > 0 && count[i]%4 == 0) {
                count[i] -= 4;
                break;
            }
        }
    }

    int flag = 0;
    rep(i, 26) {
        if(count[i] != 0) {
            flag = 1;
        }
    }

    if(!flag) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    cout << endl;
    return 0;
}