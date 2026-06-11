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

    int n;
    cin >> n;
    int A, B;
    cin >> A >> B;

    vector<long long> V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    if (B < A) {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }

    vector<pair<long long, long long>> dp(B + 1, make_pair(0, 0));
    dp[0] = make_pair(0, 1);

    auto update = [&](const pair<long long, long long>& L, const pair<long long, long long>& R) -> pair<long long, long long> {
        long long x = 0;
        if (L.second > 0) {
            x = max(x, L.first);
        }
        if (R.second > 0) {
            x = max(x, R.first);
        }
        long long cnt = 0;
        if (x == L.first) {
            cnt += L.second;
        }
        if (x == R.first) {
            cnt += R.second;
        }
        return {x, cnt};
    };

    for (auto x : V) {
        for (int i = B - 1; i >= 0; --i) {
            if (dp[i].second == 0) {
                continue;
            }
            int ni = i + 1;
            dp[ni] = update(dp[ni], make_pair(dp[i].first + x, dp[i].second));
        }
    }

    long long sum = 0;
    int sz = 1;
    long long cnt = 0;
    for (int i = A; i <= B; ++i) {
        long long P = dp[i].first;
        if (sum * i < P * sz) {
            sum = P;
            sz = i;
            cnt = 0;
        }
        if (sum * i == P * sz) {
            cnt += dp[i].second;
        }
    }

    long double avg = (long double) sum / sz;

    cout << avg << '\n' << cnt << '\n';


    return 0;
}