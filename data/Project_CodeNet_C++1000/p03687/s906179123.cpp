#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> cnt;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]]++;
    }

    int ans = 1000;
    for (auto x: cnt) {
        char c = x.first;
        

        int tans = 0;
        string ts = s;
        string ns = "";
        while (1) {
            
            bool ok = true;
            for (int i = 0; i < ts.size(); i++) {
                if (ts[i] != c) {
                    ok = false;
                }
            }
            if (ok) {
                break;
            }

            tans++;
            for (int i = 0; i < ts.size() - 1; i++) {
                if (ts[i] == c || ts[i + 1] == c) {
                    ns.push_back(c);
                }
                else {
                    ns.push_back('.');
                }
            }
            ts = ns;
            ns = "";
        }
        if (tans < ans) {
            ans = tans;
        }
    }

    cout << ans << endl;
    return 0;
}