#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    string s;   ll k;   cin >> s >> k;  int n = s.length();
    for (int i = 0; i < n; i++) {
        ll d = (26 - (s[i]-'a')) % 26;
        if (d > k)
            continue;
        
        s[i] = 'a';
        k -= d;
    }

    if (k > 0) {
        int t = s[n-1]-'a';
        s[n-1] = (k%26 + t) % 26 + 'a';
    }
    cout << s << endl;
    return 0;
}