#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();  
    for (int i = 0; i < n; ++ i) {
        if (s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2;
            return 0;
        }
        if (i + 2 < n && s[i] == s[i + 2]) {
            cout << i + 1 << " " << i + 3;
            return 0;
        }
    }
    cout << -1 << " " << -1;
}