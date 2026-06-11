#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
bool check(string &str) {
    set<char> st;
    for (auto e : str) {
        st.insert(e);
    }
    return st.size() == 1;
}
int main() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = INT_MAX;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        string prev = s;
        string now = s;
        while (!check(now)) {
            now = "";
            for (int i = 0; i < prev.size() - 1; i++) {
                if (prev[i] == ch || prev[i + 1] == ch) {
                    now.push_back(ch);
                } else {
                    now.push_back(prev[i + 1]);
                }
            }
            prev = now;
        }
        ans = min(ans, (int)s.size() - (int)now.size());
    }
    cout << ans << endl;
}
