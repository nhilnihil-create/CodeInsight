#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    
    string ans = "";
    rep(i, S.size()) {
        if (i % 2 == 0) ans.push_back(S[i]);
    }
    cout << ans << endl;
    return 0;
}
