#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s; cin >> s;
    vector<char> cs(s.begin(), s.end());
    int ans=1e7;
    for (int i=0; i<26; ++i) {
        char c='a'+i;
        if (find(cs.begin(), cs.end(), c)==cs.end()) {
            continue;
        }
        vector<char> target=cs;
        while (1) {
            bool all_same=true;
            for (auto cc : target) {
                if (cc!=c) {
                    all_same=false;
                    break;
                }
            }
            if (all_same) {
                ans=min((int)s.size()-(int)target.size(), ans);
                break;
            }
            for (int k=0; k<(int)target.size()-1; ++k) {
                if (target[k]==c||target[k+1]==c) {
                    target[k]=c;
                }
            }
            target.pop_back();
        }
    }
    cout << ans;
    return 0;
}