#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, s = 0;
    cin >> n;
    int t[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> t[i];
        s += t[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int p, x;
        cin >> p >> x;
        cout << s + x - t[p - 1] << endl;
    }
}