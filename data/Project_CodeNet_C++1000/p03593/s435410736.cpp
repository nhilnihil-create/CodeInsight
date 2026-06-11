#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()
 
const int A = 26;
int ct[A];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (const char &c : s) {
            ct[c - 'a']++;
        }
    }

    int req[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < (m + 1) / 2; j++) {
            req[(i * 2 == n - 1 ? 1 : 2) 
                * (j * 2 == m - 1 ? 1 : 2)]++;
        }
    }

    if (req[1]) {
        for (int i = 0; i < A; i++) {
            if (ct[i] & 1) {
                ct[i]--;
                break;
            }
        }
    }

    for (int i = 0; i < A; i++) {
        if (ct[i] & 1) {
            cout << "No\n";
            return 0;
        }
    }

    for (int i = 0; i < A; i++) {
        if ((ct[i] & 3)) {
            if (req[2] == 0) {
                cout << "No\n";
                return 0;
            }
            req[2]--;
            ct[i] -= 2;
        }
    }

    if (req[2] & 1) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }    

    return 0;
}