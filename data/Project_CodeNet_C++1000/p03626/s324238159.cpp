#include "bits/stdc++.h"

using namespace std;

const long long MOD = 1000000007;

int nextPattern(int curr, const string& S1, const string& S2) {
    int N = S1.size();
    if (curr >= N - 1) {
        return 0;
    }
    string s1 = S1.substr(curr + 1, 1);
    string s2 = S2.substr(curr + 1, 1);
    if (s1 == s2) {
        return 1;
    }
    else {
        return 2;
    }
}

long long dp(int curr, int prevPattern, const string& S1, const string& S2) {
    int N = S1.size();
    if (curr >= N - 1) {
        return 1LL;
    }

    int np = nextPattern(curr, S1, S2);
    long long ret = 1;
    if (prevPattern == -1) {
        if (np == 1) {
            ret = 3 * dp(curr + 1, np, S1, S2);
        }
        else {
            ret = 6 * dp(curr + 2, np, S1, S2);
        }
    }
    else if (prevPattern == 1) {
        if (np == 1) {
            ret = 2 * dp(curr + 1, np, S1, S2);
        }
        else {
            ret = 2 * dp(curr + 2, np, S1, S2);
        }
    }
    else { // prevPattern == 2
        if (np == 1) {
            ret = 1 * dp(curr + 1, np, S1, S2);
        }
        else {
            ret = 3 * dp(curr + 2, np, S1, S2);
        }
    }
    return ret % MOD;
}

void Main() {
    int N;
    cin >> N;
    string S1, S2;
    cin >> S1;
    cin >> S2;

    long long ans = dp(-1, -1, S1, S2);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
