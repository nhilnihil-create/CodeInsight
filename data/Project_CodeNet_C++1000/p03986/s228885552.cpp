#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string X;
    cin >> X;
    
    int S_cnt = 0, T_cnt = 0;
    rep(i, X.size()) {
        if (X[i] == 'T') {
            if (S_cnt >= 1) {
                --S_cnt;
            } else {
                ++T_cnt;
            }
        } else {
            ++S_cnt;
        }
    }
    cout << S_cnt + T_cnt << endl;
    return 0;
}
