#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int x = 0, max_x = 0;
    for (char c : s)
        if (c == 'I')
            max_x = max(max_x, ++x);
        else
            x--;
    
    cout << max_x << endl;
}