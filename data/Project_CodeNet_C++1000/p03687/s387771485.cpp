#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 100000;

int main() {
    string s;
    int ans = inf;
    cin >> s;
    set<char>v;
    for (int i = 0; i < s.size(); i++) {
        v.insert(s[i]);
    }

    for (auto itr = s.begin(); itr != s.end(); itr++) {
        int Max = 0;
        int last = 0;
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == *itr) {
                last = j;
                Max = max(Max, cnt); 
                cnt = 0;
            } else {
                cnt++;
            }
        }
        Max = max((int)s.size()-last-1, Max); 
        ans = min(ans, Max);
    }
    cout << ans << endl;
}
