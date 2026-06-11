#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    unordered_map<char, int> m;

    for (int i = 0; i < s.size(); ++i) {
        m[s[i]]++;
    }

    int t = 1;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second % 2 != 0) {
            t = 0 ;
        }
    }

    cout << (t == 1 ? "Yes" : "No");
}
