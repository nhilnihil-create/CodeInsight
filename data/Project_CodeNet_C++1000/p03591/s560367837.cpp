#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, ans = "";
    cin >> s;

    for (int i = 0; i < 4; i++)
    {
        ans += s[i];
    }
    if (ans == "YAKI")
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    
    
}