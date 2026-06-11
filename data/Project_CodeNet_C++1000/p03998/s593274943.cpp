#include <bits/stdc++.h>

using namespace std;

int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    int idxa = 0, idxb = 0, idxc = 0;
    char curr_player = 'a';
    while (true) {
        if (curr_player == 'a') {
            if (idxa == sa.length()) {
                cout << "A";
                return 0;
            }
            curr_player = sa[idxa];
            idxa++;
        } else if (curr_player == 'b') {
            if (idxb == sb.length()) {
                cout << "B";
                return 0;
            }
            curr_player = sb[idxb];
            idxb++;
        } else {
            if (idxc == sc.length()) {
                cout << "C";
                return 0;
            }
            curr_player = sc[idxc];
            idxc++;
        }
    }
}