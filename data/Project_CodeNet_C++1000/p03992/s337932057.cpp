#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;

    cin >> s;

    cout << s.substr(0,4) << ' ' << s.substr(4) << '\n';
    
    return 0;
}