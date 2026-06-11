#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, before = 0, after = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') after++;
        else after--;
        if (after < 0)
        {
            before++;
            after++;
        }
    }
    for (int i = 0; i < before; i++) cout << '(';
    cout << s;
    for (int i = 0; i < after; i++) cout << ')';
}