#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void) {
    io;
    string s; cin >> s;
    int count[26] = {0};
    for (int i = 0; i < (int)s.size(); i++) {
        count[s[i]-'a']++;
    }
    for (int i = 0; i < (int)s.size(); i++) {
        int x = count[s[i]-'a'];
        if (x & 1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}

