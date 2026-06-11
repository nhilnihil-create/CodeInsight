#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int n;
string s;

int main() {
    cin >> s;
    n = s.length();
    for(char c : s) mp[c] ++;
    if(mp.size() == 2) return cout << "Second" << endl, 0;
    if(n >= 4 && mp.size() == 3) {
        for(int i = 1; i < n - 1; i++) {
            if(mp[s[i]] == 1) {
                return cout << (s[i-1] == s[i+1] ? "Second" : "First") << endl, 0;
            }
        }
    }
    cout << (((s[0] == s[n-1]) ^ (n % 2 == 1) ? "First" : "Second")) << endl;
}