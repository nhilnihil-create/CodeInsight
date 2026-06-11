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
    int N, K;
    cin >> N >> K;
    vector<char> D(N);
    rep(i, K) {
        int tmp;
        cin >> tmp;
        D[i] = '0' + tmp;
    }


    for(int i=N; i<= 1000000; ++i) {
        string s = to_string(i);
        bool ok = true;
        for(auto d: D) {
            if(s.find(d) != string::npos) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << s << endl;
            return 0;
        }
    }
    return 0;
}

