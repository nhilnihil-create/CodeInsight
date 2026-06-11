#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;
const int INF = 101234567;

int main() {
    string s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    map<char, int>m;
    for (int i = 25; i >= 0; i--) {
        m[alphabet[i]] = 26 - i;
    }
    ll K;
    cin >> s;
    cin >> K;

    int i = 0;
    while (K > 0) {
        if (i == s.size()-1) {
            break;
        }
        if (s[i] == 'a') {
            i++;
            continue;
        } else {
            if (m[s[i]] <= K) {
                K -= m[s[i]];
                s[i] = 'a';
            }
        }
        i++;
    } 
    K %= 26;
    int loc = 26 - m[s[i]];
    loc += K;
    loc %= 26;
    s[i] = alphabet[loc];
    cout << s << endl;
}

