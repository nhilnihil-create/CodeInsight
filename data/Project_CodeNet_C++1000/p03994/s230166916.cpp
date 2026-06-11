#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int K;
    cin >> K;

    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') continue;
        
        int shift = 'z' - (s[i]) + 1;
        if (shift <= K) {
            s[i] = 'a';
            K -= shift;
        }
    }

    if (K > 0) {
        K %= 26;
        int ascii = ((s[n - 1] - 'a') + K) % 26;
        s[n - 1] = char('a' + ascii);
    }
    cout << s << endl;
    return 0;
}