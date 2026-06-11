#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;cin >> S;
    set<char> st;
    for (auto c : S) {
        st.insert(c);
    }
    if (st.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 100;
    for (char key = 'a'; key <= 'z'; key++) {
        string s = S;
        bool is_unmatch = true;
        int count = 1;
        while (is_unmatch) {
            string tmp_s;
            is_unmatch = false;
            for (int i = 0; i < s.size()-1; i++) {
                if (s[i] == key || s[i+1] == key) tmp_s.push_back(key);
                else {
                    is_unmatch = true;
                    tmp_s.push_back(s[i]);
                }
            }
            if (is_unmatch == true) {
                count++;
                s = tmp_s;
            }
        }
        ans = min(ans, count);
    }

    cout << ans << endl;
}