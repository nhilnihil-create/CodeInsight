#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    string s;
    string comp = "abcdefghijklmnopqrstuvwxyz";
    bool check[26] = {false};
    cin >> s;
    for (char c: s) {
        for (int i=0; i<26; i++) {
            if (c == comp[i]) check[i] = true;
        }
    }
    string ans = "None";
    for (int i=0; i<26; i++) {
        if (!check[i]) {
            ans = comp[i];
            break;
        }
    }
    cout << ans << '\n';
    
    return 0;
}