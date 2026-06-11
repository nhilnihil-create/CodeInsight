#include <bits/stdc++.h>
using namespace std;
const char same = 'o';
const char diff = 'x';

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // 1 : 羊, -1 : 狼, 0 : 未定
    auto judge = [&](int a, int b, int c)->bool {
        vector<int> v(n, 0);
        v[0] = a; v[1] = b; v[2] = c;
        for (int i = 2; i < n-1; i++) {
            if (v[i] == 1) {
                if (s[i] == same) v[i+1] = v[i-1];
                else v[i+1] = -v[i-1];
            } else {
                if (s[i] == same) v[i+1] = -v[i-1];
                else v[i+1] = v[i-1];
            }
        }
        for (int i = 0; i < n; i++) {
            int l = i-1, r = i+1;
            if (l < 0) l = n-1;
            if (n <= r) r = 0;
            if (v[i] == 1) {
                if (s[i] == same && v[l] != v[r]) return false;
                else if (s[i] == diff && v[l] == v[r]) return false;
            } else {
                if (s[i] == same && v[l] == v[r]) return false;
                else if (s[i] == diff && v[l] != v[r]) return false;
            }
        }
        return true;
    };
    
    string ans = "-1";
    auto make_ans = [&](int a, int b, int c)->string {
        vector<int> v(n, 0);
        v[0] = a; v[1] = b; v[2] = c;
        for (int i = 2; i < n-1; i++) {
            if (v[i] == 1) {
                if (s[i] == same) v[i+1] = v[i-1];
                else v[i+1] = -v[i-1];
            } else {
                if (s[i] == same) v[i+1] = -v[i-1];
                else v[i+1] = v[i-1];
            }
        }
        string ret = "";
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) ret = ret + "S";
            else ret = ret + "W";
        }
        return ret;
    };
    
    for (int bit = 0; bit < (1<<3); bit++) {
        int m[3];
        for (int i = 0; i < 3; i++) {
            if (bit&(1<<i)) m[i] = 1;
            else m[i] = -1;
        }
        if (judge(m[0], m[1], m[2])) {
            ans = make_ans(m[0], m[1], m[2]);
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}