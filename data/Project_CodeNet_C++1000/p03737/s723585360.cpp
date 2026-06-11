#include<bits/stdc++.h>
using namespace std;
    
int main() {
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    cout << (char)(s[0][0] - 0x20) << (char)(s[1][0] - 0x20) << (char)(s[2][0] - 0x20);
    return 0;
}