#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s[3];
    char diff = 'a' - 'A';
    cin >> s[0] >> s[1] >> s[2];

    for(int i=0;i<3;i++) {
        s[i][0] -= diff;
    }
    cout << s[0][0] << s[1][0] << s[2][0] << endl;
    return 0;
}
