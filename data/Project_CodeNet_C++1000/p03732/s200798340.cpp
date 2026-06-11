#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
vector<vector<long long>> vec(10);
int main() {
    long long n, w;
    cin >> n >> w;
    long long sw, sv;
    cin >> sw >> sv;
    vec[0].emplace_back(sv);
    for (int i = 0; i < n - 1; i++) {
        long long nw, nv;
        cin >> nw >> nv;
        vec[nw - sw].emplace_back(nv);
    }
    sort(vec[0].rbegin(), vec[0].rend());
    sort(vec[1].rbegin(), vec[1].rend());
    sort(vec[2].rbegin(), vec[2].rend());
    sort(vec[3].rbegin(), vec[3].rend());
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < vec[i].size(); j++) {
            vec[i][j] += vec[i][j - 1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < vec[0].size()+1; i++) {
        for (int j = 0; j < vec[1].size()+1; j++) {
            for (int k = 0; k < vec[2].size()+1; k++) {
                for (int l = 0; l < vec[3].size()+1; l++) {
                    long long co = 0;
                    co += sw * i;
                    co += (sw + 1) * j;
                    co += (sw + 2) * k;
                    co += (sw + 3) * l;
                    if (co <= w) {
                        long long a = 0;
                        if (i != 0) {
                            a += vec[0][i - 1];
                        }
                        if (j != 0) {
                            a += vec[1][j - 1];
                        }
                        if (k != 0) {
                            a += vec[2][k - 1];
                        }
                        if (l != 0) {
                            a += vec[3][l - 1];
                        }
                        if (a > ans) {
                            ans = a;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

