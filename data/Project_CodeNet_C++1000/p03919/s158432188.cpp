#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, a, n) for (int i = a; i < (n); i++)
#define all(in) in.begin(), in.end()
const int INF = 1e9;
const int MOD = 1e9 + 7;
int main() {
    int H, W;
    cin >> H >> W;
    string S[H][W];
    pair<int, int> ans;
    rep(i, H) rep(k, W) {
        cin >> S[i][k];
        if (S[i][k] == "snuke") {
            ans.first = i + 1, ans.second = k + 1;
        }
    }
    int count = 1;
    for (char i = 'A'; i <= 'Z'; i++) {
        if (count == ans.second) {
            cout << i << ans.first << endl;
            return 0;
        }
        count++;
    }
    return 0;
}