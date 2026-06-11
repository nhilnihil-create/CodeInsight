#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    int ans = 0;
    int cnt = 0;
    cin >> s;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == 'T') {
            cnt++;
        } else {
            if (cnt > 0) {
                ans++;
                cnt--;
            }
        }

    }
    cout << s.size() - ans*2 << endl;
}
