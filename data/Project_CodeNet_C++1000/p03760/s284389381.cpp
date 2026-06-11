#include <bits/stdc++.h>
using namespace std;
int main() {
    string o, e;
    cin >> o >> e;
    int m = o.length(), n = e.length();
    char t[m + n];
    for (int i = 0; i < m + n; i++)
    {
        if (i % 2 == 0) t[i] = o[i / 2];
        else t[i] = e[i / 2];
        cout << t[i];
    }
}