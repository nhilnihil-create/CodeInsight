#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    bool flag = true;
    cin >> S;
    if (S[0] != 'Y') flag = false;
    if (S[1] != 'A') flag = false;
    if (S[2] != 'K') flag = false;
    if (S[3] != 'I') flag = false;

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
