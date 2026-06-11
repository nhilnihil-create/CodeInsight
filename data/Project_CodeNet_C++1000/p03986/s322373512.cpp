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
using testimony = pair<set<int>, set<int>>;

int main() {
    string X;
    cin >> X;
    int skipped = 0;
    int num_s = 0;
    for(auto c: X) {
        if(c == 'T') {
            if(num_s > 0) {
                num_s--;
            } else {
                skipped++;
            }
        }
        if(c =='S') {
            num_s++;
        }
    }
    cout << skipped + num_s << endl;

    return 0;
}

