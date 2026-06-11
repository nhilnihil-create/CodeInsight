#include <bits/stdc++.h>
using namespace std;

char neighbor(char me, char other, char answer) {
    if (answer == 'o') {
        if (me == 'S') {
            if (other == 'S') {
                return 'S';
            } else {
                return 'W';
            }
        } else {
            if (other == 'S') {
                return 'W';
            } else {
                return 'S';
            }

        }
    } else {
        if (me == 'S') {
            if (other == 'S') {
                return 'W';
            } else {
                return 'S';
            }
        } else {
            if (other == 'S') {
                return 'S';
            } else {
                return 'W';
            }
        }
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    char st[4][2]{{'S', 'S'}, {'S', 'W'}, {'W', 'S'}, {'W', 'W'}};
    for (int i = 0; i < 4; i++) {
        char t[n]{st[i][0], st[i][1]};

        char last = neighbor(t[0], t[1], s[0]);

        for (int j = 1; j < n - 1; j++) {
            t[j+1] = neighbor(t[j], t[j-1], s[j]);
        }

        if (last == t[n-1] && t[0] == neighbor(t[n-1], t[n-2], s[n-1])) {
            for (int k = 0; k < n; k++) {
                cout << t[k];
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
