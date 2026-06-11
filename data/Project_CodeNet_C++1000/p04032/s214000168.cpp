#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    string S;

    cin >> S;

    int n = S.length();

    int l = -1;
    int r = -1;
    for (int ch = 'a'; ch <= 'z'; ++ch) {
        map<int,int> M;
        int sum = 0;
        int pre = -1;
        for (int i = 0; i < n; ++i) {
            int cur = sum;
            if (S[i] == ch) {
                ++sum;
            } else {
                --sum;
            }
            // auto it = M.lower_bound(sum);
            // if (it != M.begin()) {
            //     --it;
            //     int len = i - (it->second);
            //     if (len >= 2) {
            //         l = it->second + 1;
            //         r = i;
            //         break;
            //     }
            // }
            auto it = M.begin();
            if (it != M.end() && it->first < sum) {
               l = it->second + 1;
               r = i;
               break;
            }
    
            if (M.count(cur) == 0) {
                M[cur] = i - 1;
            }
        }
        if (l >= 0) {
            break;
        }
    }

    if (l >= 0) {
        ++l, ++r;
    }
    cout << l << " " << r << "\n";


    return 0;
}