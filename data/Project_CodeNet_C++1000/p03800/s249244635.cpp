#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100005
bool sheep[MAXN];  
int main() {
    int n;
    string s;
    cin >> n >> s;
    bool p1[4] = {true, false, true, false};
    bool p2[4] = {true, true, false, false};
    for (int p = 0; p < 4; p++) {
    sheep[1] = p1[p];
    sheep[2] = p2[p];
    for (int i = 2; i <= n; i++) {
        char ans = s[i - 1];
        if (ans == 'o') {
            if (sheep[i]) {
                if (sheep[i - 1]) {
                    sheep[i + 1] = true;
                }
                else {
                    sheep[i + 1] = false;
                }
            }
            else {
                if (sheep[i - 1]) {
                    sheep[i + 1] = false;
                }
                else {
                    sheep[i + 1] = true;;
                }
            }
        }
        else {
            if (sheep[i]) {
                if (sheep[i - 1]) {
                    sheep[i + 1] = false;
                }
                else {
                    sheep[i + 1] = true;
                }
            }
            else {
                if (sheep[i - 1]) {
                    sheep[i + 1] = true;
                }
                else {
                    sheep[i + 1] = false;
                }
            }
        }
    }
    bool ok = true;
    if (sheep[1]) {
    if (s[0] == 'o') {
        if (sheep[n] != sheep[2]) {
            ok = false;
        }
    }
    else {
        if (sheep[n] == sheep[2]) {
            ok = false;
        }
    }
    }
    else {
       if (s[0] == 'o') {
        if (sheep[n] == sheep[2]) {
            ok = false;
        }
    }
    else {
        if (sheep[n] != sheep[2]) {
            ok = false;
        }
    } 
    }
    if (sheep[n + 1] != sheep[1]) {
        ok = false;
    }
    if (ok) {
        for (int i = 1; i <= n; i++) {
            if (sheep[i]) {
                cout << 'S';
            }
            else {
                cout << 'W';
            }
        }
        cout << endl;
        return 0;
    }
    }
    cout << -1 << endl;
    return 0;
}