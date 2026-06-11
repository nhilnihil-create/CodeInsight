#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s;
    int n = s.length();
    if(n == 2 && s[0] == s[1]){
        cout << 1 << " " << 2 << '\n';
        return 0;
    }
    for(int i = 0; i <= n - 3; i++){
        string k = s.substr(i, 3);
        sort(k.begin(), k.end());
        if(k[0] == k[1] || k[1] == k[2]){
            cout << i + 1 << " " << i + 3 << '\n';
            return 0;
        }
    }
    cout << -1 << " " << -1 << '\n';
    return 0;
}