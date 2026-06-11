#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    string s;
    cin >> s;
    int n = s.size();
    map <char, int> c;
    for (auto to : s) {
        c[to] = true;
    }
    if ((c['W'] ^ c['E']) == 1|| (c['N'] ^ c['S']) == 1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}
