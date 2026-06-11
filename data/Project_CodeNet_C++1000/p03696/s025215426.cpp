#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int pref = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == ')') {
            pref++;
        } else if (S[i] == '(') {
            pref = max(--pref, 0);
        }
    }

    reverse(S.begin(), S.end());
    for (int i = 0; i < pref; i++) {
        S.push_back('(');
    }

    reverse(S.begin(), S.end());

    int suf = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == ')') {
            suf--;
        } else if (S[i] == '(') {
            suf++;
        }
    }

    for (int i = 0; i < suf; i++) {
        S.push_back(')');
    }

    cout << S << endl;

    return 0;
}
