#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int K; cin >> K;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == 'a') continue;
        if((int)('z' - s[i]) + 1 <= K) {
            K -= (int)('z' - s[i]) + 1;
            s[i] = 'a';
        }
    }
    K %= 26;
    s[s.size() - 1] = char(int(s[s.size() - 1]) + K);
    cout << s << '\n'; 
}