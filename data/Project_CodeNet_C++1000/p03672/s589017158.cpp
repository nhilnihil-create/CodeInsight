#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;
    cin >> S; 
    for(int i = S.size() - 1; i > 0; --i) {
        if (i % 2 != 0) {
            // 奇数
            continue;
        } else {
            // 偶数
            string s_l, s_r;
            s_l = S.substr(0, i / 2);
            s_r = S.substr(i / 2, (i - i / 2));
            // cout << s_l << ":" << s_r << endl;
            if (s_l == s_r) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;


    return 0;
}
