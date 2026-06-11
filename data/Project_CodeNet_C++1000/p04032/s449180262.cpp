#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans;
    string s; cin >> s;
    s += 'A';
    for(int i = 0; i < s.length()-2; i++) {
        if (s.at(i) == s.at(i+1)) {
            ans = i;
            cout << ans + 1 << " " <<  ans + 2 << endl;
            break;
        }
        if (s.at(i) == s.at(i+2)) {
            ans = i;
            cout << ans + 1 << " " << ans + 3 << endl;
            break;
        } 
        if (i == s.length() - 3) {
            cout << -1 << " " << -1 << endl;
        }
    }  
}