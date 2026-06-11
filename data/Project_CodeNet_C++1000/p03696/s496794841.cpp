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
    int N;
    cin >> N;
    string S;
    cin >> S;
    int n_open = 0;
    int n_close = 0;
    for(auto c: S) {
        if(c == '(') {
            ++n_close;
        }
        else {
            if(n_close>0) {
                --n_close;
            } else {
                ++n_open;
            }
        }
    }
    string ret;
    rep(i, n_open) {
        ret += '(';
    }
    ret += S;
    rep(i, n_close) {
        ret += ')';
    }
    cout << ret << endl;
    return 0;
}

