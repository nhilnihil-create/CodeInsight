#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<int> v;
    for(int i = 26; i >= 1; i--) {
        v.push_back(i);
    }
    v[0] = 0;
    for(int i = 0; i < n; i++) {
        int x = v[s[i]-'a'];
        if(x <= k) {
            s[i] = 'a';
            k -= x;
        } else {
            continue;
        }
    }
    k %= 26;
    s[n-1] = char(s[n-1]+k);
    cout << s << "\n";
    return 0;
}