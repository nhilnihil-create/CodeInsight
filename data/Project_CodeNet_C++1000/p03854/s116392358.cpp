#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
    vector<string> cand = {
        "dream", "dreamer", "erase", "eraser",
    };
    for(auto &s: cand) {
        reverse(s.begin(), s.end());
    }

    string S;
    cin >> S;
    reverse(S.begin(), S.end());

    int pos = 0;
    while(!S.empty()) {
        int newpos;
        for(auto ca: cand) {
            newpos = S.rfind(ca, 0);
            if(newpos != -1) {
                newpos += ca.size();
                break;
            }
        }
        if(newpos == -1) {
            cout << "NO" << endl;
            return 0;
        } else {
            pos = newpos;
            S = S.substr(pos);
        }
    }

    cout << "YES" << endl;
    return 0;
}

