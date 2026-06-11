#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    
    vector<char> go = {'N', 'W', 'S', 'E'};
    vector<int> cnt(4, 0);
    rep(i, S.size()) rep(j, 4) {
        if (S[i] == go[j]) ++cnt[j];
    }
    string ans = "Yes";
    if (cnt[0] > 0 && cnt[2] == 0) ans = "No";
    if (cnt[1] > 0 && cnt[3] == 0) ans = "No";
    if (cnt[2] > 0 && cnt[0] == 0) ans = "No";
    if (cnt[3] > 0 && cnt[1] == 0) ans = "No";
    cout << ans << endl;
    return 0;
}
