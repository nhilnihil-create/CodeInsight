#include <bits/stdc++.h>

using namespace std;

int main() {
    string w;
    cin >> w;
    char c[w.length()];
    for (int i = 0; i < w.length(); i++) {
        c[i] = w[i];
    }
    sort (c, c+w.length());
    bool beauty = true;
    int num = 1;
    char current = c[0];
    if (w.length() % 2 == 1) {
        beauty = false;
    }
    else {
        for (int i = 1; i < w.length(); i++) {
            if (c[i] == current) {
                num++;
            }
            else {
                if (num % 2 == 0) {
                    current = c[i];
                    num = 1;
                }
                else {
                    beauty = false;
                    break;
                }
            }
        }
    }

    if (beauty == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}

