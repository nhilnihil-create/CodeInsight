#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    string S;
    Int N;
    cin >> S;
    N = S.size();

    vector<string> s(4);
    s[0] = "maerd";
    s[1] = "remaerd";
    s[2] = "esare";
    s[3] = "resare";

    reverse(S.begin(),S.end());

    while(S.size() > 0) {
        bool flag = false;
        rep (i,4) {
            if (S.substr(0,s[i].size()) == s[i]) {
                flag = true;
                S = S.substr(s[i].size());
                break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}