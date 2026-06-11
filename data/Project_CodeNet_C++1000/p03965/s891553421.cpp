#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int ans = 0;
    rep(i, s.size()) {
        if (i & 1) {
            if (s[i] == 'g') ++ans;
        } else {
            if (s[i] == 'p') --ans;
        }
    }
    cout << ans << endl;
    return 0;
}
