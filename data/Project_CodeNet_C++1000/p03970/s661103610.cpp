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
    string S;
    string T = "CODEFESTIVAL2016";
    cin >> S;
    int ret = 0;
    rep(i, 16) {
        if(S[i] != T[i]) ret++;
    }
    cout << ret << endl;
    return 0;
}

