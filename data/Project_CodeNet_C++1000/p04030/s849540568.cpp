#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    string s; cin >> s;
    string res;
    int len = (int) s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'B' && res.size() != 0) {
            res.pop_back();
        } else {
            if (s[i] != 'B')
                res.push_back(s[i]);
        }
    }
    cout << res << "\n";
    return 0;
}
