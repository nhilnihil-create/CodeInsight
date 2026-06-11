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
    int64_t ret = 0;
    int tmp;
    int64_t subret = 0;
    rep(i, N) {
        cin >> tmp;
        if(tmp > 0) {
            subret += tmp;
        } else {
            ret += subret / 2;
            subret = 0;
        }
    }
    ret += subret / 2;


    cout << ret << endl;


    return 0;
}

