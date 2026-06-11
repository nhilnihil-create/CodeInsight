#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using lint = long long;

const int INF = 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    S = 'A' + S;
    int N = S.size();

    vector<int> num(26), split(1, INF - 10);
    vector<vector<int>> appear(26, vector<int>(1, INF));
    for (int i = N - 1; i > 0; i--) {
        num[S[i] - 'a']++;
        appear[S[i] - 'a'].push_back(i);
        if (*min_element(num.begin(), num.end()) == 1) {
            split.push_back(i - 1);
            for (int j = 0; j < 26; j++) {
                num[j] = 0;
            }
        }
    }

    reverse(split.begin(), split.end());
    for (int i = 0; i < 26; i++) {
        reverse(appear[i].begin(), appear[i].end());
    }

    string ans;
    int pos = 0, k = 0, K = split.size();
    while (k < K) {
        for (int i = 0; i < 26; i++) {
            int npos = *lower_bound(appear[i].begin(), appear[i].end(), pos + 1);
            if (npos > split[k]) {
                pos = npos;
                ans += char('a' + i);
                k++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}