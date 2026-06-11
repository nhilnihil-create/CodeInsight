#include <bits/stdc++.h>
using namespace std;

int main(){
    string a; cin >> a;
    vector<int64_t> c(26, 0); for (char i : a) c[i - 'a']++;
    int64_t ans = (int64_t)a.size() * ((int64_t)a.size() - 1) / 2 + 1;
    for (auto i = 0; i < 26; i++) ans -= c[i] * (c[i] - 1) / 2;
    cout << ans << endl;
    return 0;
}