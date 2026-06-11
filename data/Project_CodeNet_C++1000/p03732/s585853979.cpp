#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong N, W;
vector<llong> value[5];
llong w0;

int main() {
    cin >> N >> W;

    {
        llong v;
        cin >> w0 >> v;
        value[0].push_back(v);
    }

    for (int i = 1; i < N; i++) {
        llong v, w;
        cin >> w >> v;
        value[w - w0].push_back(v);
    }

    for (int i = 0; i < 5; i++) {
        sort(value[i].rbegin(), value[i].rend());
        value[i].push_back(0);
        for (int j = value[i].size() - 1; j > 0; j--) {
            value[i][j - 1] += value[i][j];
        }
    }
    
    llong ans = 0;
    for (int i = 0; i < value[0].size(); i++) {
        for (int j = 0; j < value[1].size(); j++) {
            for (int k = 0; k < value[2].size(); k++) {
                for (int l = 0; l < value[3].size(); l++) {
                    if (w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3) * l <= W) {
                        ans = max(ans,
                                  value[0][0] - value[0][i] +
                                  value[1][0] - value[1][j] +
                                  value[2][0] - value[2][k] +
                                  value[3][0] - value[3][l]);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
