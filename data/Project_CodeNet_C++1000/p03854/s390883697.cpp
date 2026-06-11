#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;

    ll n = 0, k;
    bool result = true;
    while(n < S.length() && result) {
        ll k = S.length() - n;
        if(k >= 5) {
            string sClip = S.substr(n, 5);
            if(sClip == "dream") {
                n += 5;
                if(k >= 7 && S.substr(n, 2) == "er") {
                    n += 2;
                    if(k >= 8 && S[n] == 'a') {
                        n -= 2;
                    }
                }
            } else if(sClip == "erase") {
                n += 5;
                if(k >= 6 && S[n] == 'r') {
                    n += 1;
                }
            } else {
                result = false;
            }
        } else {
            result = false;
        }
    }

    if(result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}