#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    vector<string> t = {"NS", "WE", "NEWS"};
    for (int i = 0; i < 3; i++) {
        sort(all(t[i]));
    }
    string s;
    cin >> s;
    sort(all(s));
    s.erase(unique(s.begin(), s.end()), s.end());
    if (find(all(t), s) == t.end()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
