#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'I') a[i] = a[i - 1] + 1;
        else if (s[i - 1] == 'D') a[i] = a[i - 1] - 1;
    }
    sort(a, a + n + 1);
    cout << a[n];
}