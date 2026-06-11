#include<bits/stdc++.h>
using namespace std;
    
int main() {
    string s[3];
    int n[3] = {0, 0, 0};
    cin >> s[0] >> s[1] >> s[2];
    int id = 0;
    while (true) {
        if (n[id] >= s[id].size()) {
            break;
        } else {
            id = (int)(s[id][n[id]++] - 0x31) - (int)'0';
        }
    }
    cout << (char)(id + 65);
    return 0;
}