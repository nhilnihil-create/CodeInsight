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
    int64_t K;
    cin >> S >> K;
    for(auto& c: S) {
        if(c == 'a') {
            continue;
        }
        auto d = 'z' - c + 1;
        if(d <= K) {
            c = 'a';
            K -= d;
        }
    }
    K %= 26;
    S[S.size()-1] += K;
    if(S[S.size()-1] > 'z')
        S[S.size()-1] -= 'a' - 1;

    cout << S << endl;

    return 0;
}

